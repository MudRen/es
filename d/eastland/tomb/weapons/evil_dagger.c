#include <mudlib.h>
inherit WEAPON;
 
void create()
{
 
        set_name( "evil dagger", "а��ذ" );
        add( "id", ({ "dagger" }) );
        set_short( "а��ذ" );
        set_long(
                "����һ�������ذ��,�հѵײ�����һ����­ͷ,���������в�ʱ��˸������Ĺ�â��\n"
        );
        set( "unit", "��" );
        set( "weapon_class", 30 );
        set("type","dagger");
        set( "min_damage", 20);
        set( "max_damage", "@@check_ali" );
        set( "weight", 25 );
        set( "second", 1 );
        set( "value", ({ 1500 , "silver" }) );
}
 
int check_ali()
{
    object holder;
    int my_ali,max;
 
    holder = this_player();
    my_ali = (int)holder->query("alignment");
        max = (my_ali < -10000) ? 10 : (-my_ali/1000);
        return (max + 20);
}
 
int stop_wield()
{
        object holder;
        int my_ali;

        holder = this_player();
        my_ali = (int)holder->query("alignment");
        if (my_ali > 0) {
                notify_fail( 
                "ذ���ϴ���һ�����������,ʹ���ղ�ס��!!\n" 
                           );
        return 1;
	}
	return 0;
}

