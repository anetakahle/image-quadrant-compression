#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


vector<vector<bool>> obrazek = vector<vector<bool>>();

struct pseudo_loss_function
{
    int zero, one, choose;
};

int find_min_choose(pseudo_loss_function sub_loss[4]){
    int minimum = (1 << 31) - 1;
    for (size_t a = 0; a < 4; a++)
    {
        for (size_t b = 0; b < 4; b++)
        {   
            if (a != b)
            {
                int local_min = 0;
                for (size_t c = 0; c < 4; c++)
                {
                    if (a == c)
                        {local_min += sub_loss[c].one;}
                    else if (b == c)
                        {local_min += sub_loss[c].zero;}
                    else {local_min += sub_loss[c].choose;}
                }
                if (local_min < minimum)
                    {minimum = local_min;}
            }
        }
    }
    return minimum;
}

pseudo_loss_function fun4to1(pseudo_loss_function sub_loss[4]){
    pseudo_loss_function loss_4to1 = pseudo_loss_function();
    loss_4to1.zero = sub_loss[0].zero + sub_loss[1].zero + sub_loss[2].zero + sub_loss[3].zero;
    loss_4to1.one = sub_loss[0].one + sub_loss[1].one + sub_loss[2].one + sub_loss[3].one;
    loss_4to1.choose = find_min_choose(sub_loss); 
    return loss_4to1;  
}

pseudo_loss_function vyhodnot_kvadrant(int velikost, int x_souradnice, int y_souradnice){//levy horni roh
    
    //basecase 1x1

    if (velikost == 1)
    {   
        pseudo_loss_function pixel;
        pixel.choose = 0; 
        if (obrazek[y_souradnice][x_souradnice] == true)
            {pixel.one = 0;
            pixel.zero = 1;}
        else {pixel.one = 1;
            pixel.zero = 0;}

        return pixel;
    }

    //jinak vyhodnot 4 mensi

    else {
        pseudo_loss_function kvadranty[4] = {
            vyhodnot_kvadrant(velikost/2, x_souradnice, y_souradnice),
            vyhodnot_kvadrant(velikost/2, x_souradnice+velikost/2, y_souradnice),
            vyhodnot_kvadrant(velikost/2, x_souradnice, y_souradnice+velikost/2),
            vyhodnot_kvadrant(velikost/2, x_souradnice+velikost/2, y_souradnice+velikost/2)
        };
        return fun4to1(kvadranty);
    }

}




int main()
{

    int rozmer;

    for (size_t i = 0; i < 3; i++)
    {getchar();}
    scanf("%d %d", &rozmer, &rozmer);
    

    for (size_t i = 0; i < rozmer; i++)
    {   
        vector<bool> radek = vector<bool>();
        for (size_t j = 0; j < rozmer; j++)
        {
            getchar();
            radek.push_back('1' == getchar());            
        }
        obrazek.push_back(radek);
    }
    
    printf("%d",vyhodnot_kvadrant(rozmer, 0, 0).choose);
    


    

}
