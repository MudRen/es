
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        seteuid(getuid());
        set_name( "occult knife", "����С��" );
        add( "id",({ "axe" }) );
        set_short( "����С��" );
        set_long(
            "����һ�ѽ���(vivisect)����\n"
        );
        set( "unit", "��");
        set( "weapon_class", 1 );

        set( "type", "axe" );
        set( "min_damage", 1 );
        set( "max_damage", 2 );
        set( "weight", 20 );
        set( "value", ({ 1, "gold" }) );
}

void init()
{
  add_action("to_vivisect","vivisect");
 }
  
int to_vivisect(string str)
{  
   object ob1,ob2,ob3,ob4;
   
   if (!str||str==""){
     write( "��Ҫ����ʲ��\n" );
          return 1;
           }
   else if (str=="corpse"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       if (ob3=(present("corpse",ob2))){
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
