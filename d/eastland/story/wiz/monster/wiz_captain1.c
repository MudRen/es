#include "../../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "The captain of Wizard bodyguard", "�ʹ������ӳ�" );
	add( "id", ({ "bodyguard","captain","guard" }) );
	set_short( "�ʹ������ӳ�" );
	set_long(@C_LONG
���ǡ����̳ǡ��ʹ������ӳ�����ʱ�쵼����������ʹ��İ�ȫ�������ش󡣽���
�ӳ���С�ͱ�������������ʮ�˰����գ������������䣬��Ч�������������Ĺ���
����᲻����Ҳ��˱��ܳ������ء�����������Ѳ�ӻʹ���ȫ�������Եĸ�������
��
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 500 );
        set( "wealth/gold",100);
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set_skill( "parry", 90 );
        set_skill( "polearm", 90 );
        set_skill( "block", 90 );
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp", 350);
        set_temp("be_joke",100);
        set_temp("bs",100);
        set("special_defense", ([ "all":50, "none":35]) );
        set("aim_difficulty",
          (["critical":60,"vascular":60,"ganglion":60,"weakest":60]) );
        set("stun_difficulty",90);
        set_natural_armor(80,24);
        set_natural_weapon(13,11,7);
        set("bodyguard",1);
        set("tactic","assault");
        wield_weapon(SWWEA"polearm2");
        equip_armor(SWARM"wiz_shield2");
        set("tactic_func","my_tactic");  
        set("inquiry",([
           "killer":"@@ask_killer",
        ]) );
        set("chat_chance",1);
        set("chat_output",({
            "�ӳ�����������治֪������Ĵ̿�(killer)��㵽���\n"
        }) );
}
void ask_killer(object asker)
{
   write(@LONG
�ӳ�˵�������칬������һ���̿ͣ���Ȼʧ����һЩ����������û��������
���������������������εľв������������ˣ��治֪�������ڻ��������
������������ ����
LONG
   );   
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("bodyguard") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                     
    if( !victim=query_attacker() ) return 0;
                        
    couples = filter_array( all_inventory(environment(this_object())),
              "can_help", this_object() );
    max = sizeof(couples);
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), sprintf(
           "%s�󺰵������������Ҳ��ˣ���ҿ챣���ʹ��İ�ȫ��\n"
           ,couples[i]->query("c_name")));
        couples[i]->kill_ob(victim);
    }
    return 0;
}
