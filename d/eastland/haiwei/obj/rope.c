#include <mudlib.h>

inherit CONTAINER;

void create()
{
        
        seteuid(getuid());
        set_name( "rope", "����" );
        set_short( "����" );
   set_long( "һ�������ӡ�\n" );
        set( "weight", 18 );
        set( "value", ({ 1, "silver" }) );
}

void init()
{
  add_action("to_throw","throw");
 }
  
int to_throw(string str)
{
  object ob1,ob2;
  int test;
   if (str!="rope")  return 0;      
   else if (str=="rope"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       test=ob2->query("layuter_hole");
       if (test==1){
       tell_room(this_object(),this_player()->query("c_name")+"����һ�����ӣ����������˶��С�\n",this_player());
       write("������Ӷ�����ס�����ʯ��Ȼ�������������붴�ڣ���˳�ֽ�������������\n");
       this_player()->move_player("/d/eastland/haiwei/hole1","SNEAK");
       return 1;
        } 
      else write("�㽫�����������µ�������\n");            
      }
    return notify_fail("�����ϲ�û�����ӣ�\n");
  } 
 }
