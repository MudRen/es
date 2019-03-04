#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("seven blunt","�߱���");
        add("id",({"blunt",}) );
       set_short("�߱���");
       set_long(@C_LONG
�߱��𴱴�˵�ǽ�ħ������ϡ���������ԭ���Ƿ���������ʮ������,������ס
������������,����,ǧ����ǰ��һ����ħ��ս��ʧ���˼䡣���,Ҳ�ñ����ڷ���
�����һ�����ħ�˻����˳���Ϊ���˼䡣��˵��,�߱��𴱻�����һ���÷�, ��
����...........����ʮ������Ϊ�ϲߡ�,��ʱ���Ѿò�֪���Ƿ�ɵö�? 
C_LONG
               );
	set( "unit", "��" );
 	setup_weapon("blunt",30,10,25);
	set( "weight", 80 );
	set( "value", ({ 240, "gold" }) );
        set_c_verbs( ({ 
           "�ſ������%s���һ������ı�������%s��Ҫ����ȥ",
           "˫�ָ߸ߵؾ���%s,бб�ؿ���%s",
           "�ֳ�%sһ�п��Ƽ�Ϊ��׾�Ĺ�������%s��ȥ",
           "��%s���ڱ���Ŀ�����������%s��ȥ"
        }) );
}
void init()
{
   add_action("do_fly","fly");
}
int do_fly(string arg)
{
   object me,*usr,target,env;
   string *envname ;
   
   if ( !living(environment(this_object())) ) {
      tell_object(this_player(),
        "��һֱ�������ϵ��߱��𴱺����ɡ�,����һ��Ҳ�������ƺ��������㡫��\n");
      tell_room(environment(this_object()),this_player()->query("c_name")+
        "�������׵ض������ϵ��߱��𴱺����ɡ�,���߱����ƺ���Ҳ������\n",
        this_player() );
      return 1;  
   }
   usr=users();
   me=this_player();
   target = usr[ random( sizeof(usr)-1 )];
   env = environment(target) ;
   
   if ( me->query("hit_points") < 120 ) {
      tell_object(me,"��,��̫�����ˡ���\n");
      return 1;
   }
   if(!env) {
      tell_object(me,"����һ�Ρ���\n");
      return 1 ;
   }  
   envname = explode(base_name(env),"/") ;
                
   if((envname[0] != "d")|| !environment(target)->query("outside")) {
     tell_object(me,"����һ�Ρ���\n"); 
     return 1 ;
   }
   if( wizardp(target) || target == me ) {
     tell_object(me,"����һ�Ρ���\n");
     return 1;
   }
   me->set("hit_points",30);
   tell_object(me,
      "����߱��𴱵�ɡ��,�ݡ���\n\n");  
   tell_room(environment(me),me->query("c_name")+
      "���߱��𴱵�ɡ��,�ݡ��������˾Ͳ����ˡ���\n\n",me);
   me->move_player(environment(target),"SNEAK");
   tell_object(me,
      "�ݡ���������߱��𴱷ɵ���һ����ֵĵط�.......�������ﰡ?\n\n");
   tell_room(environment(target),
      "�ݡ�������ĳ������ˤ��������\n\n",me);
   return 1;   
}
