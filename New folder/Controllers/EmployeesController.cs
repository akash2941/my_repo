using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebDatabaseApp.Models;

namespace WebDatabaseApp.Controllers
{
    public class EmployeesController : Controller
    {
        // GET: Employees
        public ActionResult Index()
        {

            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

            cn.Open();

            SqlCommand cmd = new SqlCommand();
            cmd.Connection = cn;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from Employees";
            List<Employee> Emps = new List<Employee>();
            SqlDataReader dr = cmd.ExecuteReader();

            while (dr.Read())
            {
                foreach (object ob in dr)
                {
                    Emps.Add(new Employee {EmpNo=dr.GetInt32(0),Name = dr.GetString(1),Basic = dr.GetDecimal(2),DeptNo = dr.GetInt32(3) });
                }
            }
            dr.Close();

            cn.Close();

            return View(Emps);
        }

        // GET: Employees/Details/5
        public ActionResult Details(int EmpNo=0)
        {
            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

            cn.Open();

            SqlCommand cmd = new SqlCommand();
            cmd.Connection = cn;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from Employees where EmpNo = @EmpNo";

            cmd.Parameters.AddWithValue("@EmpNo", EmpNo);
            SqlDataReader dr = cmd.ExecuteReader();
            Employee obj = new Employee();
            while (dr.Read())
            {
                obj.EmpNo = dr.GetInt32(0);
                obj.Name = dr.GetString(1);
                obj.Basic = dr.GetDecimal(2);
                obj.DeptNo = dr.GetInt32(3);
            }

            
            return View(obj);
        }

        // GET: Employees/Create
        public ActionResult Create()
        {


            return View();
        }

        // POST: Employees/Create
        [HttpPost]
        public ActionResult Create(Employee obj)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

                cn.Open();
                //SqlCommand cmdUpdate;
                SqlCommand cmdUpdate = new SqlCommand();
                cmdUpdate.Connection = cn;
                cmdUpdate.CommandType = CommandType.Text;
                cmdUpdate.CommandText = "insert into  Employees values(@EmpNo, @Name, @Basic, @DeptNo )";

                int EmpNo = obj.EmpNo;
                String Name = obj.Name;
                decimal Basic = obj.Basic;
                int DeptNo = obj.DeptNo;

                cmdUpdate.Parameters.AddWithValue("@EmpNo", EmpNo);
                cmdUpdate.Parameters.AddWithValue("@Name", Name);
                cmdUpdate.Parameters.AddWithValue("@Basic", Basic);
                cmdUpdate.Parameters.AddWithValue("@DeptNo", DeptNo);

                int i = cmdUpdate.ExecuteNonQuery();

                cn.Close();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Employees/Edit/5
        public ActionResult Edit(int EmpNo=0)
        {
            SqlConnection cn = new SqlConnection();

            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
            cn.Open();

            SqlCommand cmdEdit = new SqlCommand();
            cmdEdit.Connection = cn;
            cmdEdit.CommandType = CommandType.Text;
            cmdEdit.CommandText = "select * from Employees where EmpNo = @EmpNo";
            cmdEdit.Parameters.AddWithValue("@EmpNo", EmpNo);
            Employee obj = new Employee();
            SqlDataReader dr = cmdEdit.ExecuteReader();
            while(dr.Read())
            {
                obj.EmpNo = dr.GetInt32(0);
                obj.Name = dr.GetString(1);
                obj.Basic = dr.GetDecimal(2);
                obj.DeptNo = dr.GetInt32(3);
            }

          
           
            return View(obj);
        }

        // POST: Employees/Edit/5
        [HttpPost]
        public ActionResult Edit(int? EmpNo, Employee obj)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

                cn.Open();
                //SqlCommand cmdUpdate;
                SqlCommand cmdUpdate = new SqlCommand();
                cmdUpdate.Connection = cn;
                cmdUpdate.CommandType = CommandType.Text;
                cmdUpdate.CommandText = "update   Employees set Name =  @Name,Basic =  @Basic, DeptNo = @DeptNo where EmpNo = @EmpNo";

                int Empno = obj.EmpNo;
                String Name = obj.Name;
                decimal Basic = obj.Basic;
                int DeptNo = obj.DeptNo;

                cmdUpdate.Parameters.AddWithValue("@EmpNo", Empno);
                cmdUpdate.Parameters.AddWithValue("@Name", Name);
                cmdUpdate.Parameters.AddWithValue("@Basic", Basic);
                cmdUpdate.Parameters.AddWithValue("@DeptNo", DeptNo);

                int i = cmdUpdate.ExecuteNonQuery();

                cn.Close();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Employees/Delete/5
        public ActionResult Delete(int EmpNo=0)
        {

            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";
            cn.Open();

            SqlCommand cmdDel = new SqlCommand();
            cmdDel.Connection= cn;
            cmdDel.CommandType = CommandType.Text;
            cmdDel.CommandText = "select * from Employees where EmpNo = @EmpNo";
            cmdDel.Parameters.AddWithValue("@EmpNo", EmpNo);

            Employee obj = new Employee();
            SqlDataReader dr = cmdDel.ExecuteReader();
            while (dr.Read())
            {
                obj.EmpNo = dr.GetInt32(0);
                obj.Name = dr.GetString(1);
                obj.Basic = dr.GetDecimal(2);
                obj.DeptNo = dr.GetInt32(3);
            }
            return View(obj);
        }

        // POST: Employees/Delete/5
        [HttpPost]
        public ActionResult Delete(int EmpNo, Employee obj)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(localdb)\MsSqlLocalDb;Initial Catalog=JKDec20;Integrated Security=true";

                cn.Open();
                //SqlCommand cmdUpdate;
                SqlCommand cmdUpdate = new SqlCommand();
                cmdUpdate.Connection = cn;
                cmdUpdate.CommandType = CommandType.Text;
                cmdUpdate.CommandText = "delete from  Employees where EmpNo = @EmpNo";

               // int EmpNo = obj.EmpNo;

                cmdUpdate.Parameters.AddWithValue("@EmpNo", EmpNo);
                

                int i = cmdUpdate.ExecuteNonQuery();

                cn.Close();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
