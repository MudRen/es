#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "snake scale dagger","����ذ��");
        add( "id",({ "dagger" }) );
        set_short( "����ذ��");
        set_long(
@C_LONG
���ǰ��ɰ�����ߵ�������ĥ�Ƶķ���ذ�ף����еĲ�����ڶ�û
���κεĹ����Ǵ��ߵ���Ƭ�����е����磬����������֩��ͼ��
�����֡�
C_LONG
        );
        set( "unit", "��");
        set( "weapon_class", 22);
        set( "type", "dagger" );
        set( "min_damage", 16 );
        set( "max_damage", 24 );
        set( "weight", 50 );
        set( "bleeding", 10);
        set( "value", ({ 710, "silver" }) );
}
