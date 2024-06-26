﻿using _102220129_PhanVanToan.BLL;
using _102220129_PhanVanToan.DTO;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _102220129_PhanVanToan.View
{
    public partial class PhanVanToan_MF : Form
    {
        public PhanVanToan_MF()
        {
            InitializeComponent();
            SetCBB();
            Init();
            SetCBBSort();
        }
        public void SetCBB()
        {
            this.cbbCategory.Items.Clear();
            this.cbbCategory.Items.Add(new CBBItem
            {
                Text = "All",
                Value = 0
            });
            this.cbbCategory.Items.AddRange(BLL_QLTV.Instance.GetCBBItems().ToArray());
            this.cbbCategory.SelectedIndex = 0;
            this.cbbCategory.DropDownStyle = ComboBoxStyle.DropDownList;
        }
        public void Init()
        {
            dgv.ReadOnly = true;
            var data = BLL_QLTV.Instance.GetAll();
            dgv.DataSource = data;
        }
        public void SetCBBSort()
        {
            this.cbbSort.Items.Clear();
            for (int i = 0; i < dgv.Columns.Count; i++)
            {
                this.cbbSort.Items.Add(dgv.Columns[i].HeaderText.ToString());
            }
            this.cbbSort.SelectedIndex = 0;
            this.cbbSort.DropDownStyle = ComboBoxStyle.DropDownList;
        }
        public void ShowData()
        {
            var data = BLL_QLTV.Instance.GetAll(txtSearch.Text, cbbCategory.SelectedItem.ToString(), cbbSort.SelectedItem.ToString());
            dgv.DataSource = data;
        }

        private void cbbLSH_SelectedIndexChanged(object sender, EventArgs e)
        {
            Init();
            if(cbbCategory.SelectedIndex != 0)
            {
                ShowData();
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            ShowData();
        }

        private void btnSort_Click(object sender, EventArgs e)
        {
            ShowData();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            PhanVanToan_DF f = new PhanVanToan_DF();
            f.ShowData += new PhanVanToan_DF.MyDel(this.ShowData);
            f.ShowDialog();
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            if (dgv.SelectedRows.Count == 1)
            {
                PhanVanToan_DF f = new PhanVanToan_DF(dgv.SelectedRows[0].Cells["IdBook"].Value.ToString());
                f.ShowData += new PhanVanToan_DF.MyDel(this.ShowData);
                f.ShowDialog();
            } else
            {
                MessageBox.Show("Chỉnh sửa mỗi lần 1 quyển sách");
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            if (dgv.SelectedRows.Count == 0 )
            {
                MessageBox.Show("Chọn quyển sách cần xóa");
            } else
            {
                foreach (DataGridViewRow row in dgv.SelectedRows)
                {
                    string id = row.Cells["IdBook"].Value.ToString();
                    BLL_QLTV.Instance.DelSV(id);
                }
                ShowData();
            }
        }
    }
}
