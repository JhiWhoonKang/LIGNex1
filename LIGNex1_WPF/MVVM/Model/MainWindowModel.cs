using System;
using System.ComponentModel;

namespace MVVM.Model
{
    class MainWindowModel : INotifyPropertyChanged
    {
        private int num = 1;

        public int Num
        {
            get { return num; }
            set { num = value; onPropertyChanged("Num"); }
        }

        private string name = "aaa";
        public string Name
        {
            get { return name; }
            set { name = value; onPropertyChanged("Name"); }
        }

        public event PropertyChangedEventHandler? PropertyChanged;
        protected void onPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
        }
    }
}
