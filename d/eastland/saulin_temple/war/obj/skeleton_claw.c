#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "skeleton claws", "�׹�צ" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "�׹�צ" );
        set_long(
                "����һ˫������ɫ��â��צ�ӣ�����˿˿�ĺ�����\n"
        );
        set( "unit", "˫" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 970, "silver" }) );
        set_c_verbs( ({ "��%s��%sһץ", "%s����һ�����ɫ�����⣬ɨ��%s",
                "��%s��˻����һ������%s��ȥ" }) );
}
