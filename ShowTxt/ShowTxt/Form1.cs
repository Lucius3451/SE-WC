using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ShowTxt
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        List<string> Temp_store = new List<string>();
        string defaultfile = "";

        private bool Isalpha(char aim)
        {
            if (aim < 65 || aim > 122 || (aim > 90 && aim < 97))
                return false;
            else
                return true;
        }

        private bool Blank_Check(string aim)
        {
            int len, i, prv;

            if ((len = aim.Length) != 0)
            {
                for (i = prv = 0; i < len; i++)
                {
                    if (aim[i] != ' ' && (aim[i] < 0 || aim[i] > 31) && aim[i] != 127)
                    {
                        if (prv != 0)
                            return false;
                        else
                            prv = 1;
                    }
                }
            }
            return true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            //FolderBrowserDialog dialog = new FolderBrowserDialog();
            //dialog.Description = "请选择一个文件";
            //dialog.ShowNewFolderButton = false;
            //dialog.ShowDialog();
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Title = "请选择一个文本文件";
            dialog.Multiselect = false;
            dialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            dialog.ShowDialog();
            defaultfile = dialog.FileName;
            this.textBox1.Text = defaultfile;
            ///在这里完成
            /// 清空
            /// 文件输入
            StreamReader read = new StreamReader(defaultfile, Encoding.Default);
            Temp_store.Clear();
            for (string temp = ""; (temp = read.ReadLine()) != null; )
            {
                Temp_store.Add(temp);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (this.textBox1.Text == "")
            {
                MessageBox.Show("请先选择一个文本文件");
            }
            else if (this.comboBox1.Text == "")
            {
                MessageBox.Show("请先选择要执行的操作");
            }
            else if (this.comboBox1.Text == "-c(统计字符数)")
            {
                int i, count, len, j, lll;
                count = 0;
                if ((len = Temp_store.Count()) != 0)
                {
                    for (i = 0; i < len; i++)
                    {
                        for (j = 0, lll = Temp_store[i].Length; j < lll; j++)
                        {
                            if (Isalpha(Temp_store[i][j]))
                                count++;
                        }
                    }
                }
                MessageBox.Show(this.textBox1.Text + "字符数为" + count.ToString());
            }
            else if (this.comboBox1.Text == "-w(统计单词数)")
            {
                int i, count, len, j, lll;
                count = 0;
                if ((len = Temp_store.Count()) != 0)
                {
                    for (i = 0; i < len; i++)
                    {
                        for (j = 0, lll = Temp_store[i].Length; j < lll - 1; j++)
                        {
                            if (Isalpha(Temp_store[i][j]) && !Isalpha(Temp_store[i][j + 1]))
                                count++;
                        }
                        ///MessageBox.Show(lll + "\n" + Temp_store[i]);
                        
                        if (j < lll && Isalpha(Temp_store[i][j])) //这样就不会检测空行了
                            count++;
                    }
                }
                MessageBox.Show(this.textBox1.Text + "单词数为" + count.ToString());
            }
            else if (this.comboBox1.Text == "-l(统计行数)")
            {
                MessageBox.Show(this.textBox1.Text + "有" + Temp_store.Count() + "行。");
            }
            else //if (this.comboBox1.Text == "-a(统计不同行数)")
            {
                if (Temp_store.Count() == 0)
                {
                    MessageBox.Show(this.textBox1.Text + "是空的.");
                }
                else
                {
                    int i, lines, blank, remark, sp;
                    for (i = blank = remark = sp = 0, lines = Temp_store.Count(); i < lines; i++)
                    {
                        if (Blank_Check(Temp_store[i]))
                            blank++;
                        else
                        {
                            sp++;
                            if (Temp_store.IndexOf("//") != -1)
                                remark++;
                        }
                    }
                    MessageBox.Show("Blank lines:" + blank.ToString() +
                        "\nRemark lines:" + remark.ToString() +
                        "\ncode lines:" + sp.ToString());
                }
            }
        }
    }
}
