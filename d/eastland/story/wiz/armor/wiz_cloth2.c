#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine robe","ҩʦ����" );
     add( "id",({ "cloth","robe"}) );
     set_short( "ҩʦ����" );
     set_long(@C_LONG
һ�������Ƴɵ��·���������·�������Ϳ��ĳЩҩ�ģ��������������ͷ���ġ�
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "body" );
     set( "material","healer" );
     set( "armor_class",32);
     set( "defense_bonus",7 );
     set( "value",({ 1000,"silver" }) );
     set("special_defense",
        (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
}
