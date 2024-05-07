using System;
using System.IO;

namespace zad1
{
    class Program
    {
        static void Main(string[] args)
        {

            string inputCSV = args[0];
            string outputHTML = args[1];

            StreamWriter sw = new StreamWriter(outputHTML);

            WriteHeader(sw);
            WriteTableHeader(sw);

            try
            {
                StreamReader sr = new StreamReader(inputCSV);

                string line = sr.ReadLine();
                string[] header = line.Split(',');

                WriteTableHeaderRow(sw, header);

                while ((line = sr.ReadLine()) != null)
                {
                    string[] words = line.Split(',');
                    WriteTableRow(sw, words);
                }

                sr.Close();

                WriteFooter(sw);

                sw.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
        }

        static void WriteHeader(StreamWriter sw)
        {
            sw.WriteLine("<!DOCTYPE html> <html> <head> <style> table {font-family: arial, sans-serif; border-collapse: collapse; width: 100%;} td, th {border: 1px solid #dddddd; text-align: left; padding: 8px;} tr:nth-child(even) {background-color: #dddddd;} </style> </head> <body> <table style=\"width:100%\">");
        }

        static void WriteTableHeader(StreamWriter sw)
        {
            sw.WriteLine("<tr>");
        }

        static void WriteTableHeaderRow(StreamWriter sw, string[] header)
        {
            foreach (var word in header)
            {
                sw.WriteLine("<th>" + $"{word}" + "</th>");
            }
            sw.WriteLine("</tr>");
        }

        static void WriteTableRow(StreamWriter sw, string[] words)
        {
            sw.WriteLine("<tr>");

            foreach (var word in words)
            {
                sw.WriteLine("<td>" + $"{word}" + "</td>");
            }

            sw.WriteLine("</tr>");
        }

        static void WriteFooter(StreamWriter sw)
        {
            sw.WriteLine("</table> </body> </html>");
        }
    }
}