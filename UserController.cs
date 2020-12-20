using MVCAssignment.Models;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace MVCAssignment.Controllers
{
    public class UserController : Controller
    {
        // GET: User
        public ActionResult Index()
        {
            List<User> li = new List<User>();
            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
            cn.Open();

            SqlCommand cmd = new SqlCommand();
            cmd.Connection = cn;
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "select * from Users";
            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                li.Add(new User {UserName=(string)dr["UserName"], Password = (string)dr["Password"],
                FullName = (string)dr["FullName"],Email=(string)dr["Email"],CityId=(int)dr["CityId"],PhoneNo= (string)dr["PhoneNo"]
                });
            }
            return View(li);
        }

        // GET: User/Details/5
        public ActionResult Details(string UserName="")
        {
            User user = new User();

            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
            cn.Open();

            SqlCommand cmd = new SqlCommand();
            cmd.Connection = cn;
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "select * from Users where UserName = @UserName";
            cmd.Parameters.AddWithValue("@UserName", UserName);

            SqlDataReader dr = cmd.ExecuteReader();
            dr.Read();
            user = new User
            {
                UserName = (string)dr["UserName"],
                Password = (string)dr["Password"],
                FullName = (string)dr["FullName"],
                Email = (string)dr["Email"],
                CityId = (int)dr["CityId"],
                PhoneNo = (string)dr["PhoneNo"]
            };
            return View(user);
        }

        // GET: User/Create
        public ActionResult Create()
        {
            User user = new User();

            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

            con.Open();

            SqlCommand command = new SqlCommand();
            command.Connection = con;
            command.CommandType = CommandType.Text;
            command.CommandText = "select * from Cities";

            SqlDataReader dr = command.ExecuteReader();

            List<SelectListItem> list = new List<SelectListItem>();
            while (dr.Read())
            {
                list.Add(new SelectListItem { Text = (string)dr["CityName"], Value = Convert.ToInt32(dr["CityId"]).ToString() });
            }
            user.Cities = list;
            dr.Close();
            con.Close();


            return View(user);

        }

        // POST: User/Create
        [HttpPost]
        public ActionResult Create(User user)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
                cn.Open();

                SqlCommand cmd = new SqlCommand();
                cmd.Connection = cn;
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                cmd.CommandText = "InsertUser";
               // cmd.Parameters.AddWithValue("@UserId", user.UserId);
                cmd.Parameters.AddWithValue("@UserName", user.UserName);
                cmd.Parameters.AddWithValue("@Password", user.Password);
                cmd.Parameters.AddWithValue("@FullName", user.FullName);
                cmd.Parameters.AddWithValue("@Email", user.Email);
                cmd.Parameters.AddWithValue("@CityId", user.CityId);
                cmd.Parameters.AddWithValue("@PhoneNo", user.PhoneNo);
                cmd.ExecuteNonQuery();


                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
        public ActionResult Login()
        {
            HttpCookie objCookie1 = Request.Cookies["UserInfo"];
            if (objCookie1 != null)
            {
                return RedirectToAction("Home");
            }
            else
            {
                User user = new User();
                return View(user);
            }

        }

        [HttpPost]
        public ActionResult Login(User user)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
                cn.Open();

                SqlCommand cmd = new SqlCommand();
                cmd.Connection = cn;
                cmd.CommandType = System.Data.CommandType.Text;
                cmd.CommandText = "select * from Users where UserName = @UserName and Password = @Password";
                cmd.Parameters.AddWithValue("@UserName", user.UserName);
                cmd.Parameters.AddWithValue("@Password", user.Password);


                SqlDataReader dr = cmd.ExecuteReader();

                if (user.IsActive == true)
                {

                    if (dr.Read())
                    {
                        HttpCookie objCookie = new HttpCookie("UserInfo");
                        objCookie.Expires = DateTime.Now.AddDays(1);
                        objCookie.Values["UserName"] = user.UserName;
                        objCookie.Values["Password"] = user.Password;
                        Response.Cookies.Add(objCookie);

                        Session["UserName"] = (string)dr["UserName"];
                        
                        return RedirectToAction("Home");
                    }
                    else
                    {
                        return RedirectToAction("Login");
                    }
                }
                else
                {
                    if (dr.Read())
                    {
                        Session["UserName"] = (string)dr["UserName"];
                        return RedirectToAction("Home");
                    }
                    else
                    {
                        return RedirectToAction("Login");
                    }
                }

            }
            catch
            {
                return View("Create");
            }
        }

        public ActionResult Home()
        {
            if (Session["UserName"] == null)
            {
                return RedirectToAction("Login");
            }
            else
            {
                if (Request.Cookies["UserInfo"] != null)
                {
                    HttpCookie req = Request.Cookies["UserInfo"];
                    string name = req.Values["UserName"];
                    string pass = req.Values["Password"];

                    SqlConnection cn = new SqlConnection();
                    User user = new User();
                    string UserName = Session["UserName"].ToString();

                    cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=True;Pooling=False";
                    cn.Open();

                    SqlCommand cmd = new SqlCommand();
                    cmd.Connection = cn;
                    cmd.CommandType = System.Data.CommandType.Text;
                    cmd.CommandText = "Select * from Users where UserName = @UserName ";

                    cmd.Parameters.AddWithValue("@UserName", name);

                    SqlDataReader dr = cmd.ExecuteReader();

                    dr.Read();

                    user.UserName = (string)dr["UserName"];
                    user.Password = (string)dr["Password"];
                    user.FullName = (string)dr["FullName"];
                    user.CityId = (int)dr["CityId"];
                    user.Email = (string)dr["Email"];
                    user.PhoneNo = (string)dr["PhoneNo"];
                    dr.Close();
                    cn.Close();
                    return View(user);
                }
                else if(Session["UserName"] != null)
                {
                    SqlConnection cn = new SqlConnection();
                    User user = new User();
                    string UserName = Session["UserName"].ToString();

                    cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=True;Pooling=False";
                    cn.Open();

                    SqlCommand cmd = new SqlCommand();
                    cmd.Connection = cn;
                    cmd.CommandType = System.Data.CommandType.Text;
                    cmd.CommandText = "Select * from Users where UserName = @UserName ";

                    cmd.Parameters.AddWithValue("@UserName", UserName);

                    SqlDataReader dr = cmd.ExecuteReader();

                    dr.Read();

                    user.UserName = (string)dr["UserName"];
                    user.Password = (string)dr["Password"];
                    user.FullName = (string)dr["FullName"];
                    user.CityId = (int)dr["CityId"];
                    user.Email = (string)dr["Email"];
                    user.PhoneNo = (string)dr["PhoneNo"];
                    dr.Close();
                    cn.Close();
                    return View(user);
                }
                else{
                    return RedirectToAction("Login");
                }

            }
        }

            // GET: User/Edit/5
        public ActionResult Edit()
        {
            SqlConnection con = new SqlConnection();
            User user = new User();
            string UserName = Session["UserName"].ToString();
            con.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=True;Pooling=False ; MultipleActiveResultSets = True";
            con.Open();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandType = System.Data.CommandType.Text;
            cmd.CommandText = "Select * from Users where UserName = @UserName ";
            cmd.Parameters.AddWithValue("@UserName", UserName);
            SqlDataReader dr = cmd.ExecuteReader();
            dr.Read();
            user.UserName = (string)dr["UserName"];
            user.Password = (string)dr["Password"];
            user.FullName = (string)dr["FullName"];
            user.CityId = (int)dr["CityId"];
            user.Email = (string)dr["Email"];
            user.PhoneNo = (string)dr["PhoneNo"];
            cmd.CommandText = "select * from Cities";
            dr.Close();
            SqlDataReader dr1 = cmd.ExecuteReader();

            List<SelectListItem> list = new List<SelectListItem>();
            while (dr1.Read())
            {
                list.Add(new SelectListItem { Text = (string)dr1["CityName"], Value = Convert.ToInt32(dr1["CityId"]).ToString() });
            }
            user.Cities = list;
            dr1.Close();
            con.Close();
            return View(user);
        }

        // POST: User/Edit/5
        [HttpPost]
        public ActionResult Edit(string UserName, User user)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=True;Pooling=False";
                cn.Open();

                SqlCommand cmd = new SqlCommand();
                cmd.Connection = cn;
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                cmd.CommandText = "UpdateUser";

                cmd.Parameters.AddWithValue("@UserName", user.UserName);
                cmd.Parameters.AddWithValue("@Password", user.Password);
                cmd.Parameters.AddWithValue("@FullName", user.FullName);
                cmd.Parameters.AddWithValue("@Email", user.Email);
                cmd.Parameters.AddWithValue("@CityId", user.CityId);
                cmd.Parameters.AddWithValue("@PhoneNo", user.PhoneNo);

                cmd.ExecuteNonQuery();
                cn.Close();

                return RedirectToAction("Home");
            }
            catch
            {
                return View();
            }
        }

        public ActionResult Logout()
        {
            FormsAuthentication.SignOut();
            Session["UserName"] = null;
            Session.Abandon();
            if (Request.Cookies["UserInfo"] != null)
            {
                Request.Cookies["UserInfo"].Expires = DateTime.Now.AddDays(-1);
                Response.Cookies.Add(Request.Cookies["UserInfo"]);
                return RedirectToAction("Login");
            }
            else
            {
                return RedirectToAction("Login");
            }

        }

        // GET: User/Delete/5
        public ActionResult Delete(string UserName = "")
        {
            return View();
        }

        // POST: User/Delete/5
        [HttpPost]
        public ActionResult Delete(string UserName, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        
    }
}
