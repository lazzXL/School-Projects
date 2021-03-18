using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FormsCalculadora
{
    

    public partial class Form1 : Form
    {
        double fn;
        string op;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "2";
            }
            else
            {
                tb.Text = tb.Text + "2";
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void add_Click(object sender, EventArgs e)
        {
            
            fn = Convert.ToDouble(tb.Text);
            tb.Text = "0";
            op = "+";
        }

        private void sub_Click(object sender, EventArgs e)
        {
           
            fn = Convert.ToDouble(tb.Text);
            tb.Text = "0";
            op = "-";
        }

        private void div_Click(object sender, EventArgs e)
        {
           
            fn = Convert.ToDouble(tb.Text);
            tb.Text = "0";
            op = "/";
        }

        private void mult_Click(object sender, EventArgs e)
        {
            
            fn = Convert.ToDouble(tb.Text);
            tb.Text = "0";
            op = "*";
        }

        private void iq_Click(object sender, EventArgs e)
        {
            double sn;
            double r;

            sn = Convert.ToDouble(tb.Text);

            if (op == "+")
            {
                r = (fn + sn);
                tb.Text = Convert.ToString(r);
                fn = r;
            }
            if (op == "-")
            {
                r = (fn - sn);
                tb.Text = Convert.ToString(r);
                fn = r;
            }
            if (op == "*")
            {
                r= (fn * sn);
                tb.Text = Convert.ToString(r);
                fn = r;
            }
            if (op == "/")
            {
                if (sn == 0)
                {
                    MessageBox.Show("Não se pode dividir por zero");
                    

                }
                else
                {
                    r = (fn / sn);
                    tb.Text = Convert.ToString(r);
                    fn = r;
                }
            }
        }

        private void b1_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "1";
            }
            else
            {
                tb.Text = tb.Text + "1";
            }
        }

        private void b3_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "3";
            }
            else
            {
                tb.Text = tb.Text + "3";
            }
        }

        private void b4_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "4";
            }
            else
            {
                tb.Text = tb.Text + "4";
            }
        }

        private void b5_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "5";
            }
            else
            {
                tb.Text = tb.Text + "5";
            }
        }

        private void b6_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "6";
            }
            else
            {
                tb.Text = tb.Text + "6";
            }
        }

        private void b7_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "7";
            }
            else
            {
                tb.Text = tb.Text + "7";
            }
        }

        private void b8_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "8";
            }
            else
            {
                tb.Text = tb.Text + "8";
            }
        }

        private void b9_Click(object sender, EventArgs e)
        {
            if (tb.Text == "0" && tb.Text != null)
            {
                tb.Text = "9";
            }
            else
            {
                tb.Text = tb.Text + "9";
            }
        }

        private void clr_Click(object sender, EventArgs e)
        {
            tb.Clear();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            tb.Text = tb.Text + "0";
        }

        private void dot_Click(object sender, EventArgs e)
        {
            tb.Text = tb.Text + ".";
        }

        private void Sqrt_Click(object sender, EventArgs e)
        {
            
        }
    }
}
