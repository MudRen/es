
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        seteuid(getuid());
        set_name( "dragon god drumstick", "������" );
        add( "id",({ "drumstick"}) );
        set_short( "������" );
        set_long(
            "��ѹ�鳿��Ի�(beat)��(drum)��\n"
        );
        set( "unit", "��");
        set("no_sale",1);
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 10);
        set( "max_damage", 15 );
        set( "weight", 180 );
        set( "value", ({ 50, "gold" }) );
}

void init()
{
  add_action("to_beat","beat");
 }
  
int to_beat(string str)
{  
   object owner,env,mob;
   
   if(!str||str=="") return notify_fail("��Ҫ��ʲ��??\n");
   if(str!="drum") return 0 ;
    
   owner=environment(this_object());
   if(owner!=this_player()) return 0 ; 
   
   env=environment(this_player());
   if(!(env->query("beat_control")))
         { return notify_fail("���û�к��ʵĹĿ����á�\n") ; }
   if(this_object()->query("once_beat"))
        { return notify_fail("�������Ѿ��������ˡ�\n") ; }

   this_object()->set("once_beat",1) ;
   mob=find_object_or_load(Ldmonster"dragon");   
   
   if(present(mob,env))
        {return notify_fail("����������û���κ��·���\n"); }
   mob->move(env);
   write("�Ӻ������룬һֻ���������شӺ�������������š��̬��������������\n");
   this_player()->set_explore("eastland#5");
   return 1; 
}
