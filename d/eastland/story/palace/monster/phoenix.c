#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Red phoenix","[0;31m��[1;31m��[0;37m[0;31m��[1;31m��[0;37m[0;31m��[1;31m��[m"  );
        add( "id", ({ "phoenix" }) );
        set_short( "[0;31m��[1;31m��[0;37m[0;31m��[1;31m��[0;37m[0;31m��[1;31m��[m" );
        set_long(@C_LONG
һֻ������ĳ��ȫ���̿Ҳ�Ƶķ�ˣ�ȫ����ë���ް��ӣ��������ˡ���ֻ��
�����������ˢë��������Ϊ���ڡ�
C_LONG
        );        
        set( "unit", "ֻ" );
        set( "race", "monster");
        set( "race","����");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,33,53 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "mountable", 1);
        set( "max_load", 2600 );
        set_c_limbs( ({ "���", "����", "צ", "β��","���" }) );
        set_c_verbs( ({ "%ş���צ, ��%sһץ", 
                        "%s�����������%sһ��"}) );
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("ra-shan",environment()) ) {
      tell_room(environment(),"�����л������������������ĵ��ˣ�\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="phoenix" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("ra-shan",environment()) ) {
     tell_room(environment(),sprintf("%sŭ������͵�ҵķ�ˣ��Ŷ�û�У������Ҳ��úý�ѵ�㣬���ǲ�֪��͵���Ƿ����ģ���������ȥ����\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
