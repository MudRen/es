#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Saiyada shield", "���Ǵ�֮��");
        add( "id", ({ "shield" }) );
        set_short( "���Ǵ�֮��" );
        set_long(
@C_LONG
���Ƿ��Դ�˵�е�սʿ�����Ǵ���ӵ�еĶ��ƣ�����а��ʦ��ķ��
����ĸ���Ʒ��������״Ϊһϸ������ͣ����ڱ�Ե�е�������
�ģ�����Ч�ṥħ��������
C_LONG
        );
        set( "unit", "��");
        set( "type", "shield" );
        set( "material", "light_metal" );
   set( "armor_class",9);
        set( "defense_bonus", 5 );
        set( "special_defense",
          ([ "poison":15, "fire":12, "cold":-10 ]) );
         set( "weight", 100 );
        set( "value", ({ 1300, "silver" }) );
        set( "no_sale", 1);
}
