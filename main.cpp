#include<fstream>
#include<iostream>
#include<iomanip>



using namespace std ;

class stock{
    
    int  price ;
    int stk_no ;
    float  p_e ;
    int m_cap;
    int high ;
    string s;
    string m;
    int closing ;
    int quantity;

    
    
    
    
    
    
    
public:
 static double  balance ;
 static int total_stks ;
 static int total_profit;
 int profit ; 
 
 //int quantity;
 
 stock( string st,int p ,int no ,float pe , int mc , int h, string mo,int cl)
 {
    price = p ;
    stk_no = no ;
    p_e = pe ;
    m_cap = mc ;
    high = h ;
    s = st ;
    m = mo ;
    closing=cl;
    
 }
 
int buy(stock & ); // adress dede 
 void view();
 void view_statement( stock  ); // only class 
 //void disp_tp();
 
 
 
 
    
    
};

double stock :: balance=75000; // i here encountered a error as i wanted a class variable and hence i used static


int stock:: total_stks;
int stock :: total_profit;
//int stock:: profit ;
//int stock :: quantity;

//void stock :: disp_tp()
//{
    //cout<<"\n NET PROFIT : "<<total_profit<<endl ;
//}









void stock::view()
{
cout<<s<<endl
 <<" Stock number : "<<stk_no<<endl
 <<" Current Price : "<<price<<endl
 <<" Market Capital  : "<<m_cap<<endl
 <<" 3 MONTH HIGH : "<<high<<endl
 <<" P/E Ratio : "<<p_e<<endl 
 <<" Overall Mood : "<<m<<endl;
 
}



int stock ::buy( stock &s )
{
    int t;
    int qty;
    cout<<"\n Do you want to buy this stock if yes input 1 or else press any key ";
 cin>>t;
 if(t==1)
 {
     
     cout<<" \n enter the quantity ";
     cin>>s.quantity;
     
     //s.quantity=s.quantity+qty;
     if(s.quantity==0){
         s.profit=0 ;
         cout<<"\n"<<s.quantity<<endl;
     }
     else if(balance>=350)
     {
     balance = balance - ( s.quantity* s.price );
     
      cout<<"\n  Stocks Purchased : "<<s.quantity<<endl;
      
      
      
     
     cout<<"\n the balance remaining is :"<<balance<<endl;
     
     s.profit= s.quantity*(s.closing-s.price);
     cout<<" TRANSACTION PROFIT : "<<s.profit<<endl; // remove after use just for testing 
     
     total_profit=total_profit+s.profit ;
     
     cout<<left<< setw(10)<<" TOTAL PROFIT  :"<<total_profit<<endl;
     
    
     
     
     }
     else 
     {
        cout<<"\n Insufficient Balance : [You lacked in wealth management] ";
        cout<<"\n Try wisely next time ...."<<endl;
     }
     
    return (s.profit);
}
    
}

void stock :: view_statement(stock f )
{
    //int prof=f.buy(f);

    fstream c ;

 c.open("display.txt",ios::app);

 if(c.is_open())
 {
 
 
    c <<left<<setw(20)<<f.s<<left<<setw(15)<<f.quantity<<setw(20)
        <<f.closing<<left<<setw(5)<<f.profit<<endl;
 }
    c.close();
 
        

    
}





int main()
{

int t ;

cout<<"**********************************************************************************************"<<endl;
cout<<"**********************************************************************************************"<<endl;

cout<<"\n------------------------- WELCOME TO THE STOCK MARKET SIMULATOR------------------------------"<<endl;
cout<<"\n-------------------------   $$ Learn How To Buy like A Pro $$  ------------------------------"<<endl;
cout<<"\n-------------------------   ( AN INVESTOR EDUCATION INITIAIVE )  ------------------------------"<<endl;

cout<<" \n About this stock buying  Simulator " 

  << " \n This is a basic stock buying simulator , aim of this simulator is to make beginners learn and know about "<<endl;
  
 cout<<  " 1. Various Stock Performance Indicators"<<endl;
 cout<<"\n 2. How to judge a particular stock based on its Indicators "<<endl;
 cout<<"\n 3. To give users a real time experience about how do markets work in real " << endl;
 
 cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~ LET's START OUR LEARNING JOURNEY~~~~~~~~~~~~~~~~~~"<<endl;
 
 cout<<"\n MUST READ INSTRUCTIONS AND IMPORTANT POINTS ABOUT THE INDICATORS "<<endl
        <<"\n RULES :"
        <<"1.You are Initially Given a Balance of Rs.75,000 for buying the given stocks "<<endl
        <<"2.You now have to judge the indicators wisely and hence buy the stocks smartly "<<endl
        <<"3.Your main aim here should be to MAXIMIZE THE PROFIT at the end of the day "<<endl
        <<"4.You have to  buy the preferred stock and it's quantity ."<<endl
        <<"5. At the end you will shown your result ie YOUR TOTAL PROFIT OR LOSS considering an perestimated closing value of that stock"<<endl;
        
cout<<"\n********************* INDICATORS OF STOCKS AND THEIR INFORMATION ****************** "<<endl;

cout<<"\n MARKET CAPITAL : Market capitalization refers to the total dollar market value of a company's outstanding shares of stock. Commonly referred to as market cap"<<endl
    << "it's calculated by multiplying the total number of a company's outstanding shares by the current market price of one share"<<endl
    <<"For example, a company with 10 million shares outstanding priced at $100 each would have a market cap of $1 billion."<<endl
    <<"The investment community uses this figure to determine a company's size instead of sales or total asset figures"<<endl;
    
cout<<"\n P/E RATIO  : The price-earnings ratio (P/E Ratio) is the relation between a company’s share price and earnings per share (EPS)." <<endl
    <<" It denotes what the market is willing to pay for a company’s profits. "<<endl
    <<"\n The P/E Ratio helps investors gauge the market value of a share compared to the company’s earnings."<<endl
    <<" In simple terms, you get to know how much the market is willing to pay for a stock based on the company’s past and future earnings. "<<endl;

cout<<"\n 3 MONTH HIGH : Quarterly or annual reports published by the company. If the results are positive, the stock’s price will go up." << endl
    <<"If results are negative, it might trigger a fall. " <<endl ;
    
cout<<" \n MOOD OF THE STOCK :  A bull market, typically referencing stock indices, exists when prices are on the rise."<<endl 
    <<"While individual stocks can be bullish "<<endl;
cout<<"\n BEARISH :  A BEARISH market, typically referencing stock indices, exists when prices are on the fall."<<endl
    <<" While individual stocks can be bearish "<<endl;

 
 cout<<"\n NOTE : THE MARKET CAPITAL GIVEN HERE IS IN THOUSAND CRORE FIGURES "<<endl;
 
 
 stock ONGC("ONGC",334,1,0.9,120,350,"BEARISH -- ",330);
 ONGC.view();
 ONGC.buy(ONGC);
 
 
 
 
 cout<<"\n";
 stock INFYS("INFOSYS",1400,2,1.6,480,1390,"BULLISH ++",1419);
 INFYS.view();
 INFYS.buy(INFYS);
 

    
 /*
 cout<<"\n";
 stock IOCL("INDIAN OIL ",560,3,0.8,110,800," BULLISH ++",566);
 IOCL.view();
 IOCL.buy(IOCL);
 
 cout<<"\n";
 stock TATA("TATA ",3000,4,0.4,600,3130,"BEARISH --",2998);
 TATA.view();
 TATA.buy(TATA);
 cout<<"\n";
 
 
 stock ADANI("ADANI",245,5,1.9,90,330," BULLISH ++",249);
 ADANI.view();
 ADANI.buy(ADANI);
 cout<<"\n";
 
 
 stock HUL("HUL",60,6,0.2,50,56," BULLISH ++",58);
 HUL.view();
 HUL.buy(HUL);
 cout<<"\n";
 
 stock ICICI("ICICI ",2568,7,0.7,550,3098,"NEUTRAL = ",2578);
 ICICI.view();
 ICICI.buy(ICICI);
 cout<<"\n";
 
 stock HDFC("HDFC",678,8,2.2,409,802," BULLISH ++",705);
 HDFC.view();
 HDFC.buy(HDFC); */




 












 
 cout<<"\n CHECK YOUR PORTFOLIO STATEMENT FOR FURTHER  DETAILS " <<endl;
    
  // cout<<"\n TOTAL STOCKS PURCHASED : "<<total_stks ;
 //  cout<<"\n BALANCE REMAINING : "<<balance; 
 
 //cout<<"\n NET PROFIT : "<<total_profit;
 
 //disp_tp();
 
 fstream disp ;

 disp.open("display.txt",ios::app);

 if(disp.is_open())
 {
 
 disp<<"\n *********************** FINAL PORTFOLIO *****************************" <<endl;
 
 
 disp << left <<setw(20)<<"\nCOMPANY "<< left << setw(15) << "QUANTITY " <<setw(20)
        <<"CLOSING"<< left <<setw(5) <<"PROFIT"<<endl;


    disp.close();
 }
 
 
 
 ONGC.view_statement(ONGC);
 INFYS.view_statement(INFYS);
 /*HDFC.view_statement(HDFC);
 ICICI.view_statement(ICICI);
 HUL.view_statement(HUL);
 ADANI.view_statement(ADANI);
 TATA.view_statement(TATA);
 IOCL.view_statement(IOCL);*/
 
 fstream d ;
 
 d.open("display.txt",ios::app);
 
 if(d.is_open())
 {
     
 
 d <<"\n SPECIAL TIP :  "<<endl;
 d <<"\n RULE NO. 1 -> NEVER LOOSE MONEY ,  RULE NO. 2 -> NEVER FORGET RULE 1 "<<endl;
 d <<"\n - Warren Buffet "<<endl;
 }
 
 d.close();
 
 

 
return 0 ;
}
