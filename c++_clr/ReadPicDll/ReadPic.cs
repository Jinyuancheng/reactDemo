using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ReadPicDll
{
    public class CReadPic
    {
        public CReadPic()
        {

        }
        /// <summary>
        /// 读取jpg图片数据
        /// </summary>
        /// <param name="_sPicFilePath">jpg文件路径</param>
        /// <returns></returns>
        public Byte[] ReadPicInfo(string _sPicFilePath)
        {
            if (!File.Exists(_sPicFilePath))
            {
                return null;
            }
            FileStream fileStream = new FileStream(_sPicFilePath, FileMode.OpenOrCreate);
            if (fileStream.Length == 0)
            {
                return null;
            }
            if(fileStream.Length > 200*1024)
            {
                return null;
            }
            int iLen = (int)fileStream.Length;
            Byte[] by = new Byte[iLen];
            IntPtr pFaceBuffer = Marshal.AllocHGlobal(iLen);
            fileStream.Read(by, 0, iLen);
            Marshal.Copy(by, 0, pFaceBuffer, iLen);
            fileStream.Close();
            return by;
            //return BitConverter.ToString(by);
        }
    }
}
