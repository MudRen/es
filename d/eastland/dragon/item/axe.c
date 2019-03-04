
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        
        seteuid(getuid());
        set_name( "stell axe", "�ָ�" );
        add( "id",({ "axe" }) );
        set_short( "�ָ�" );
        set("long","@@layuter_c_long");     
        set( "unit", "��");
        set( "weapon_class", 20 );
        set( "type", "axe" );
        set( "min_damage", 6 );
        set( "max_damage", 15 );
        set( "weight", 180 );
        set( "value", ({ 100, "gold" }) );
}

void init()
{
  add_action("to_chop","chop");
 }
 
 string layuter_c_long()
 {
  if (query("woodman_die"))
    return "����һ��մ��Ѫ���ĸ�ͷ��\n";
  else 
    return "�����Է������Կ�(chop)���ĸ�ͷ��\n";  
 } 
  
int to_chop(string str)
{  
   object ob1,ob2,ob3,ob4;
   int layuter_test;
   
   layuter_test=this_object()->query("woodman_die");
   if (!str||str==""){
     write("��Ҫ��ʲ��\n");
          return 0;
           }        
   else if (str=="tree"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       layuter_test=this_object()->query("woodman_die");
       if (layuter_test==1){
           write("��Ѹ�ͷ����մ��Ѫ�������̫�����㲻������������\n");
           return 1;
           }
       else if (ob3=(present("layuter_tree",ob2))){
         ob3->remove(); 
         ob4=new(Lditem"layuter_tree1");
         ob4->move(ob2);
         write("������ͷ��ʼ���������㿳�������������ķ���һ�����ص�ľ��\n");
         return 1; 
          }              
        else {
          write("���ﲢû�����뿳����\n");
            return 1; 
            } 
        }
    else {
      write(
       " �ܱ�Ǹ���㲢û�к��ʵĹ��߿��Կ���\n");
       return 1;
       }
    }   
}
