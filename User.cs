using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MVCAssignment.Models
{
    public class User
    {

        [Key]
        [DataType(DataType.Text)]
        [Required(ErrorMessage = "Please fill the feild")]
        [MaxLength(10), MinLength(4)]
        public string UserName { get; set; }

        [DataType(DataType.Password)]
        [Required(ErrorMessage = "Please fill the feild")]
        [MaxLength(10), MinLength(4)]
        public string Password { get; set; }

        [DataType(DataType.Text)]
        [Required(ErrorMessage = "Please fill the feild")]
        [MaxLength(10), MinLength(4)]
        public string FullName  { get; set; }

        [DataType(DataType.EmailAddress)]
        [Required(ErrorMessage = "Please fill the feild")]
        public string Email { get; set; }

        public int CityId { get; set; }

        [DataType(DataType.PhoneNumber)]
        [Required(ErrorMessage = "Please fill the feild")]
        [MaxLength(10), MinLength(10)]
        public string PhoneNo { get; set; }
        public IEnumerable<SelectListItem> Cities { get; set; }
        public bool IsActive { set; get; }
    }
}