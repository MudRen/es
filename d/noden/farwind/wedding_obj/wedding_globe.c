#include <mudlib.h>
inherit ARMOR;
void create()
{
   set_name( "wedding globe", "��黤��Բ��" );
	add( "id", ({ "globe" }) );
	set_short( "��黤��Բ��" );
	set_long(
	"����һ����������Բ�ֿɰ�С����,������Ҫ�����������������: \n"
	"��Զ�����ٽ��.......:p  \n");
	set("prevent_drop",1);
	set("material","element");
	set( "type", "globe" );
	set( "armor_class", 20 );
	set( "defense_bonus", 6 );
	set( "weight", 50 );
   set( "value", ({ 8000, "silver" }) );
}
/*
int query_auto_load()
{
   if( !environment() ) return 1;
   if( environment()->query("spouse") )
        return 1;
   return 0;
}
*/
int stop_equip()
{
        if( !this_player()->query("spouse") ) {
        printf(
               "���������ٴ���!\n" );
        return 1;
        }
   return 0;
}
