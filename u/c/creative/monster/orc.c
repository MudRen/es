#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
        ob->set_level( 9 );
        ob->set_name( "orc rogue", "��������å" );
        ob->add( "id", ({ "rogue", "orc" }) );
        ob->set_short( "��������å" );
        ob->set_long(
                "��������˳��������ֳ�ר��ϲ���۸���С��\n"
        );
        ob->set_perm_stat( "str", 7 );
        ob->set_perm_stat( "int", 1 );
        ob->set_perm_stat( "kar", 2 );
        ob->set_skill( "unarmed", 40 );
        ob->set( "alignment", -700 );
        ob->set( "natural_weapon_class1", 5 );
        ob->set( "natural_min_damage1", 3 );
        ob->set( "natural_max_damage1", 6 );
        ob->set( "wealth/copper", 80 );
        ob->set( "chat_chance", 10 );
        ob->set( "chat_output", ({
                "��������å���: �����Ǯ����������Ȼ�����㡣\n",
                "��������å������ǰչʾ���ļ��⡣\n",
                "��������å˵��: ��һ�㣬���ӽ���ûʲ�����ġ�\n"
        }) );
}
