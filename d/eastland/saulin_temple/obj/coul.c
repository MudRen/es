#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "coul", "����Ͱ");
        add ("id",({ "coul"}) );
        set_short("����Ͱ");
        set("unit", "��");
        set_long(@C_LONG
����һ��װ��ˮ�Ĵ���Ͱ����Ϊ��Ͱ���ú��������������ˮ���Ѿ�
��ɱ��ˡ�
C_LONG
        );
        set("nosecond",1);
        set("weapon_class", 15);
        set("type","chain");                        
        set("min_damage", 10);
        set("max_damage", 15);
        set("weight", 30);
        set("value",({ 250, "silver"}));
}
