#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "bloody claws", "Ѫצ" );
        add( "id", ({ "claw", "claws" }) );
        set_short( "Ѫצ" );
        set_long(@C_LONG
����һ˫�١������Ƴɵĸ�צ����һ����צ��ͬ������ֻ����Ƭצ�У�
���Ƿ���Ѫ��ɫ��â��צ��ȴ��������ֱ�����Ѷ̽�ûʲ�᲻ͬ��
C_LONG
        );
        set( "unit", "˫" );
        set( "nosecond", 1 );
        setup_weapon( "unarmed", 29, 18, 23 );
        set( "bleeding", 15 );
        set( "weight", 140 );
        set( "value", ({ 2970, "silver" }) );
        set_c_verbs( ({ "��%s��%sһ��", "%s����һ��Ѫ��ɫ�����⣬ɨ��%s",
                "��%s��˻����һ������%s��ȥ", }) );
}
