#include <mudlib.h>

inherit MONSTER;

void create ()
{
    ::create();
    set_level(6);
    set_name( "small bat", "С����" );
    add ("id", ({ "bat"}) ); 
    set_short( "С����" );
    set_long(@LONG
һֻ�����ڱ��ϵ�С����        
LONG
    );
    set_natural_armor(30,2);
    set_natural_weapon( 9,3,5 );
    set ("weight", 50);
    set ("unit", "ֻ");
    set_c_verbs( ({ "%sץ%s", "%sҧ%s", }) );
    set_c_limbs( ({ "ͷ", "���", "����" }) );
}
