#include <mudlib.h>
 
inherit MONSTER;
 
void create ()
{
        ::create();
        seteuid( getuid() );
        set_level(19);
        set_name( "ted", "̩��" );
        add ("id", ({ "barman" }) );
        set_short( "Ted the barman", "����̩��" );
        set_long(@LONG
This is Ted, the owner of Ted\'s place. He looks a bit old.
Just another typical barman.
 
LONG
        , @CLONG
̩�� -- ���С��ĵ���. ���������е���, ����֮��ûɶ��ɫ.
 
CLONG
        );
        set( "alignment", 2500 );
        set( "gender", "male" );
        set( "race", "human" );
        set( "unit", "λ" );
        set("weight", 650);
        set("exp_reward", 1 );
        set("no_attack",1);
}
 
