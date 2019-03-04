#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "a white dog", "小白狗" );
    set_short( "小白狗");
    set("no_attack",1);
    set_long(@C_LONG
一只卷毛的小白狗。平时喜欢乱叼东西,所以又叫『叼叼狗』。
C_LONG
            );
    set("unit","位");
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",3100);
    set("chat_chance",5);
    set("chat_output",({
         "小白狗对你『汪汪汪』地吠著。\n"
    }) );
}        
int accept_item(object me, object item)
{
      string name;
      
      name=item->query("name");
      if (this_object()->query_temp("feed")){
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "把你给它的东西给埋在地下～～\n");
          return 0;
      }
      if (name!="white bone") {
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "把你给它的东西吃下去～～\n");
          return 0;
      }
      item->remove();
      this_object()->set_temp("feed",1);
      tell_room(environment(this_object()),this_object()->query("c_name")+
          "一溜烟地叼著你给他的东西跑到别的地方去了～～\n");  
      set_long(@C_LONG
一只卷毛的小白狗。它正在努力地理著东西。
C_LONG
            );
      this_object()->move(DBEGGAR"forest6");
      call_out("recover",180,this_object());
      return 1;
}
void recover(object obj)
{
    tell_room( environment(obj),obj->query("c_name")+
         "在埋完东西之後就又跑走了～～\n");
    set_long(@C_LONG
一只卷毛的小白狗。平时喜欢乱叼东西,所以又叫『叼叼狗』。
C_LONG
    );
    environment(obj)->delete_temp("be_searched");
    obj->delete_temp("feed");
    obj->move(DBEGGAR"vice_master_room");
}
