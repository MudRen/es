#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "do_plast", "plast" );
}
 
void create()
{
        set_name( "fragment", "���ӵ���Ƭ" );
        add( "id", ({ "fragment" }) );
        set_short( "���ӵ���Ƭ" );
        set_long( @C_LONG
����һƬ���ӵ���Ƭ����ӳ����һ�ų����ɻ�����������������������(plast)ԭ����
C_LONG
                );
                set("unit","Ƭ");
                set("weight", 10);
                set("value",({ 5, "silver"}) );
        set("no_sale", 1 );
}
 
int do_plast(string arg)
{
    if( !arg || arg != "mirror" ) {
        tell_object(this_player(),
                "���������Ƭ�����Ƕ�����\n" );
        return 0;}
    if ((string)environment(this_player())->query("short")=="������ղ���" &&
        this_player()->query_temp("look_mirror")) {
        tell_object(this_player(),
                "�����Ƭ���ؾ��ϵĽ��䣬���ӷ���һ����ů�Ĺ�ã��\n" );
        this_player()->set_temp("mirror_ok",1);
        remove();
        } else
        tell_object(this_player(),
                "���û�о��Ӱ�...\n" );
        return 1;
}
