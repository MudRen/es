

#include "../../echobomber.h"

void drink_muse(int color,object you)
{
    int exp,con,kar;
    int correct;
    int i;
    object *items;
    
    exp=you->query_experience();
    con=you->query_perm_stat("con");
    kar=you->query_perm_stat("kar");
    
    
    correct=((exp+con+kar) % 9)+1;
    
    if ( correct!=color ) {
       tell_object(you,
       "���������Ȫˮʱ,��ĺ�����Ȼһ����\n"
       );
       tell_room(environment(you),
       you->query("c_name")+"���һ��!!��......\n");
       
       you->receive_damage((int)you->query("hit_points")+10);
       return;
       }
    items=all_inventory(you);   
    for(i=0;i<sizeof(items);i++) {
       if ( (string)items[i]->query("name")=="Black Box of Molader" )
          items[i]->set("quest_action/good_poet",1);
       }   
    tell_object(you,
      "���������Ȫˮʱ,������Լ��ƺ���ø�������, ���������˵��������ں�\n"
      "�������������, ������Լ������Ϊһ�����и߶��Ļ�����ѧ��һ��.\n"
      );
    return;   
}

int fill_muse_water(object you,int color)
{
     object *items;
     int i;
     
     items=all_inventory(you);
          
     for(i=0;i<sizeof(items);i++) 
       if ( (string)items[i]->query("name")=="Black Box of Molader" ) {
          if (!items[i]->query("quest_item/black_bottle")) {
            tell_object(you,
            "��û�к��ʵ�������װ��Ȫˮ.\n"
            );
            return 1;
            }
          items[i]->set("quest_action/muse_filled",color);
          tell_object(you,
          "���ú�ɫƿ�Ӱ�Ȫˮװ��.\n"
          );
          return 1;
          }
    return 0;   
}

void drink_bottle_muse(object you,object box)
{
    int exp,con,kar;
    int correct,color;
    
    
    exp=you->query_experience();
    con=you->query_perm_stat("con");
    kar=you->query_perm_stat("kar");
    
    correct=((exp+con+kar) % 9)+1;
    
    color=box->query("quest_action/muse_filled");
    
    if ( correct!=color ) {
       tell_object(you,
       "���������Ȫˮʱ,��ĺ�����Ȼһ����\n"
       );
       tell_room(environment(you),
       you->query("c_name")+"���һ��!!��......\n");
       if ( box->query("quest_action/mixed") ) 
          you->receive_damage(10);
       else 
          you->receive_damage( (int)you->query("hit_points")+10 );
       }
    else {
      box->set("quest_action/good_poet",1);
      tell_object(you,
      "���������Ȫˮʱ,������Լ��ƺ���ø�������, ���������˵��������ں�\n"
      "�������������, ������Լ������Ϊһ�����и߶��Ļ�����ѧ��һ��.\n"
      );
      }
    
    box->set("quest_action/mixed",0);
    box->set("quest_action/muse_filled",0);
    
    return;   
}     

string muse_color(int color)
{
   string *colors;
   colors=({"��(blue)","��(green)","��(red)","��(purple)",
   "��(orange)","��(yellow)","��(black)","��(white)","��(brown)" });
   
   return colors[color-1];   
}
