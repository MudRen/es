#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky cloak", "���˶���");
        add( "id", ({ "cloak" }) );
        set_short( "���˶���" );
        set_long(
@C_LONG
�����ɫ�Ķ����˵�Ǳ��ϵ����뿪�ڰ������ʱ���͸��������
��������Ʒ���������С����ͼ����Ҳ��С͵����ı�ǣ�����
ս��ʱΪ���������ˡ�
C_LONG
        );
        set( "unit", "��");
        set( "type", "cloak" );
   set( "material", "thief" );
   set( "armor_class", 7 );
   set( "defense_bonus", 10 );
        set( "special_defense",
               ([ "fire": -10 ]) );
   set("extra_skills", ([ "dodge" : 10 ]) );
   set( "weight", 55 );
        set( "value", ({ 2650, "silver" }) );
        set( "no_sale", 1);
}
