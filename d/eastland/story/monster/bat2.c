#include <mudlib.h>

inherit MONSTER;

void create ()
{
    ::create();
    set_level(11);
    set_name( "large bat", "������" );
    add ("id", ({ "bat"}) ); 
    set_short( "������" );
    set_long(@LONG
һֻ�����ڱ��ϵĴ�����        
LONG
    );
    set_natural_armor(55,2);
    set_natural_weapon( 19,10,20 );
    set ("weight", 50);
    set ("unit", "ֻ");
    set_c_verbs( ({ "%sץ%s", "%sҧ%s", }) );
    set_c_limbs( ({ "ͷ", "���", "����" }) );
}
