using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MVVM.Model;

namespace MVVM.ViewModel
{
    class MainWindowViewModel : INotifyPropertyChanged
    {
        private MainWindowModel model;
        public MainWindowModel Model
        {
            get { return model; }
            set { model = value; onPropertyChanged("Model"); }
        }
        public MainWindowViewModel()
        {
            model = new MainWindowModel();
        }
        public event PropertyChangedEventHandler? PropertyChanged;
        protected void onPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            { 
                handler(this, new PropertyChangedEventArgs(propertyName)); 
            }
        }
    }
}
