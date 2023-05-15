#include <stdio.h>
#include <string.h>

float cal(float min_balance,int days)
{
    /*
    Balance less than Rs. 10 Cr rate of interest 2.70% p.a.
    Balance Rs. Cr and above rate of interest 3.00% p.a.
    */
   float interest_day=0;
   float total_interest = 0;
   if (min_balance<100000000)
   {
        interest_day = (min_balance *2.70/100)/365; 
   }
   else
   {
        interest_day = (min_balance *3.00/100)/365;
   }
    total_interest = days * interest_day;
    return total_interest;
}
float deposit(float min_balance, float amt)
{
    float new_balance = 0;
    new_balance += min_balance + amt;
    return new_balance;
}
float withdrawal(float min_balance, float amt)
{
    float new_balance = 0;
    new_balance = min_balance-amt;
    return new_balance;
}

int main()
{
    int ch;
    printf("Enter 1.> If you want to open a Savings A/C\n");
    printf("Enter 2.> If you want to deposit money from your Savings A/C\n");
    printf("Enter 3.> If you want to withdraw money from your Savings A/C\n");
    printf("Enter your choice:---->\n");
    scanf("%d",&ch);
    if (ch == 1)
    {
        printf("You have chosen to open a Savings A/C!!!\n");
        printf("Please provide your Personal Details as directed:---->\n");
        printf("\n");
        // Fetching Personal Details of the Customers 
        char name[50];
        char dob[15];
        char gender[15];
        char name_of[50];
        float annual_income;
        char occupation[25];
        char religion[12];
        char category[12];
        char disability[20];
        char pan_num[25];
        fflush(stdin);
        printf("Enter your Name(same as ID Proof):--->\n");
        gets(name);
        fflush(stdin);
        printf("Enter your Date Of Birth in the format DD/MM/YYYY:--->\n");
        gets(dob);
        fflush(stdin);
        printf("Enter your gender:---> Male/Female/Others\n");
        gets(gender);
        fflush(stdin);
        printf("Enter\n1.> For Father's Name\n2.> For Mother's Name\n3.> For Spouse's Name\nEntering the name of atleast one of the above mentioned persons is necessary\n");
        printf("Enter your choice:\n");
        int ch_name_of;
        scanf("%d",&ch_name_of);
        fflush(stdin);
        if (ch_name_of == 1)
        {
            printf("Enter your Father's Name:--->\n");
            gets(name_of);
        }
        else if (ch_name_of == 2)
        {
            printf("Enter your Mother's Name:--->\n");
            gets(name_of);
        }
        else
        {
            printf("Enter your Spouse's Name:---->\n");
            gets(name_of);
        }
        printf("Enter your Occupation:--->\n");
        gets(occupation);
        printf("Enter your Annual Income:--->\n");
        scanf("%f",&annual_income);
        fflush(stdin);
        printf("Enter your religion:---->\n");
        printf("Hindu/ Muslim/ Christian/ Sikh/ Others\n");
        gets(religion);
        fflush(stdin);
        printf("Enter your category:---->\n");
        printf("General/ SC/ ST/ OBC\n");
        gets(category);
        int ch_disability;
        printf("Are you a person with disability?\n");
        printf("Enter\n1.> For YES\n2.> For NO\n");
        scanf("%d",&ch_disability);
        if (ch_disability == 1)
        {   
            fflush(stdin);
            printf("Enter whether Visually Impaired or Differently Abled\n");
            gets(disability);
        }
        printf("Enter the PAN Number:--->\n");
        fflush(stdin);
        gets(pan_num);
        printf("\n");
        // Fetching the Customer's Contact Details
        char mob_num[11];
        char mail[35];
        printf("Enter your Contact Details as directed:---->\n");
        printf("Enter your Mobile Number:---->\n");
        gets(mob_num);
        fflush(stdin);
        printf("Enter your mail ID:---->\n");
        gets(mail);
        fflush(stdin);
        printf("\n");
        // Fetching the Customer's Address Details
        char city[20];
        char address[35];
        char add_type[18];
        char dist[15];
        char state[15];
        int pin;
        printf("Enter your Address Type:---->\n");
        printf("Residential/ Business/ Registered Office/ Unspecified\n");
        gets(add_type);
        fflush(stdin);
        printf("Enter your Address:---->\n");
        gets(address);
        fflush(stdin);
        printf("Enter your City or Village--->\n");
        gets(city);
        fflush(stdin);
        printf("Enter your District:----->\n");
        gets(dist);
        fflush(stdin);
        printf("Enter your State:---->\n");
        gets(state);
        fflush(stdin);
        printf("Enter you PIN Code:---->\n");
        scanf("%d",&pin);
        fflush(stdin);
        // ASSIGNING AN A/C NUMBER
        char ac_num[15];
        printf("Assigning the A/C Number:---->\n");
        scanf("%s",&ac_num);
        printf("You have been assigned the A/C Number: %s\n",ac_num);
        // Minimal Balance required for opening bank A/C
        printf("A minimum balance of Rs.3,000/- is rquired to open this A/C:\n");
        float min_balance = 0;
        min_balance = deposit(0,3000);
        printf("Now your A/C Balance is:-----> %.2f\n",min_balance);
        // Creating the Customer's Database
        char acc_details[50];
        strcpy(acc_details,name);
        strcat(acc_details," .txt");
        FILE *acc;
        acc = fopen(acc_details,"w");
        fprintf(acc,"Name: %s\nAccount Number: %s\nOccupation: %s\nAddress Type: %s\nAddress: %s\nCity or Village: %s\nDistrict: %s\nState: %s\nReligion: %s\nCategory: %s\nContact No.: %s\nMail ID: %s\nAccount Balance: %.2f",name,ac_num,occupation,add_type,address,city,dist,state,religion,category,mob_num,mail,min_balance);
        printf("YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY!!!\nTHANK YOU FOR CHOOSING OUR BANK\n");
        fclose(acc);
        // Creating the Customer Account Details
        printf("Enter amount of money to be deposited except the minimum Rs3000:\n");
        float deposit_amt;
        scanf("%f",&deposit_amt);
        float ac_balance = deposit(min_balance,deposit_amt);
        char ac_details[50];
        strcpy(ac_details,name);
        strcat(ac_details," Account.txt");
        FILE *acd;
        acd = fopen(ac_details,"w");
        fprintf(acd,"Minimum balance for your A/C is zero\n");
        fprintf(acd,"Name Of A/C holder: %s\nAccount Number: %d\nAccount Balance: %.2f\nNo. of Days: %d",name,ac_num,ac_balance,1);
        fclose(acd);
    }
    else if (ch == 2)
    {   
        printf("Enter your A/C Number:\n");
        char acc_num[12];
        scanf("%s",&acc_num);
        fflush(stdin);
        printf("Enter your name as per the A/C :\n");
        char acc_name[50];
        gets(acc_name);
        char filename[50];
        strcpy(filename,acc_name);
        strcat(filename," Account.txt");
        FILE *acd;
        acd = fopen(filename,"r");
        char account_number[50];
        int flag = 0;
        for (int i = 0; i < 17; i++)
        {
            fscanf(acd,"%s",&account_number);
        }
        account_number[strlen(account_number)+1]= '\0';
        for (int i = 0; i < 12; i++)
        {
            if(acc_num[i]==account_number[12])
            {
                flag = 1;
            }
        }
        fclose(acd);
        if (flag)
        {
            printf("Account Matched!!!\n");
                
        printf("Enter the amount of money you want to deposit:---->\n");
        float depo_amt;
        scanf("%f",&depo_amt);
        float current_balance = 0;
         current_balance += deposit(8000,depo_amt)+cal(8000,55);//Assuming that Customer is depositing after 55 days 
         printf("Your Current Balance is: %.2f",current_balance);
         FILE *ptr;
         ptr = fopen(filename,"w");
         fprintf(ptr,"Minimum balance for your A/C is zero\n");
         fprintf(ptr,"Name Of A/C holder: %s\nAccount Number: %s\nAccount Balance: %.2f\nNo. of Days: %d",acc_name,account_number,current_balance,55);
         fclose(ptr);

        
            }
        else
        {
        printf("Enter Valid Account Number!!!\n");
        }
    }
    else
    {
      printf("Enter your A/C Number:\n");
        char acc_num[12];
        scanf("%s",&acc_num);
        fflush(stdin);
        printf("Enter your name as per the A/C :\n");
        char acc_name[50];
        gets(acc_name);
        char filename[50];
        strcpy(filename,acc_name);
        strcat(filename," Account.txt");
        FILE *acd;
        acd = fopen(filename,"r");
        char account_number[50];
        int flag = 0;
        for (int i = 0; i < 17; i++)
        {
            fscanf(acd,"%s",&account_number);
        }
        account_number[strlen(account_number)+1]= '\0';
        for (int i = 0; i < 12; i++)
        {
            if(acc_num[i]==account_number[12])
            {
                flag = 1;
            }
        }
        fclose(acd);
        if (flag)
        {
            printf("Account Matched!!!\n");
            printf("Enter the amount of money to be withdrawn:--->\n");
            float amt_withdraw;
            scanf("%f",&amt_withdraw);
            float current_balance = 0;
            current_balance += withdrawal(12032.55,amt_withdraw)+cal(12032.55,75);//Assuming Customer withdraws money after 74 days
            printf("Your Current Balance is: %.2f",current_balance); 
            FILE *ptr;
         ptr = fopen(filename,"w");
         fprintf(ptr,"Minimum balance for your A/C is zero\n");
         fprintf(ptr,"Name Of A/C holder: %s\nAccount Number: %s\nAccount Balance: %.2f\nNo. of Days: %d",acc_name,account_number,current_balance,75);
         fclose(ptr);
     
        }
        return 0;
     }

}