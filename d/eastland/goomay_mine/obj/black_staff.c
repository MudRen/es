
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( " balck staff", "��ɽ����");
        add ("id",({ "staff" }) );
        set_short("a black staff", "��ɽ����");
        set_long(@AA
���Ƕ���Ϊ�ƾ��������������������Ȼ��������������û��ħ�������⹥��
������ǲ���Щ��ħ��������ľ��������Դ�����ɵ��������ʼ�Ӳ�쳣�ǲ�
��Ĺ���������
AA
);
        set( "weapon_class", 30 );
        set( "min_damage", 15);
        set( "unit","��");
        set( "max_damage", 26);
        set( "type", "blunt");
        set( "weight", 130 );
        set( "value", ({ 400, "silver" }) );
        }