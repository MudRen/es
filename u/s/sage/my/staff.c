#include <mudlib.h>
inherit WEAPON;

void create()
{
      set_name( "jin-gu staff", "�𹿰�");
        add ("id",({ "staff"}) );
     set_short( "jin-gu staff", "�𹿰�");
        set("unit", "��");
        set_long(
            "",@C_LONG
����һ�ѻ������¶����Ž��ı�����ֻҪ�㿴��һ�ۣ��;��û�����£�
��˵�������Ƕ�����һ���������룬�����������ʥ����������
�����ú��д�ţ�����𹿰�����һ�ٰ�ʮ�򹫽�
C_LONG
        );
        set( "weapon_class", 45);
        set( "type", "bo");
        set( "min_damage", 25);
        set( "max_damage", 47);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 3800, "silver" }) );
}
