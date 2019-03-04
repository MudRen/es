#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "Princess Sasami", "ɰɴ��" );
    add( "id",({"sasami","princess"}) );
    set_short( "ɰɴ������");
    set_long(@LONG
ɰɴ�����������ҵĵڶ����������Ǹ��ǳ��ɰ���СŮ�������������Ե���
��ȫ��ͬ����˵�������봬�빵ͨ�����������ԣ���ǧ��ҪС����Ŷ���˻ʹ���
ɰɴ���ĳ�����ǲ�֪���ܵ��Ķ�ȥ�ˣ�������Ӧ�����һ����Ļ����������
���й��˻ʹ�(luoky)����ϸ���εģ�
LONG
            );
    set("unit","λ");
    set("race","daemon");      
    set("class","healer");
    set("age",10);
    set("gender","female" );
    set("alignment",800);
    set("weight",300);
    set("wealth/gold",150);
    set_perm_stat("str",18);
    set_perm_stat("dex",15);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set_perm_stat("pie",30);
    set("time_to_heal",30);
    set("hit_points",500);
    set("max_hp",500);
    set("spell_points",200);
    set("max_sp",200);
    set_natural_armor(55,27);
    set_natural_weapon(45,0,15);
    set_skill("dagger",70);
    set_skill("anatomlogy",90);
    set_skill("dodge",70);
    set_skill("block",80);
    set_skill("tactic",80);
    set("tactic","assault");
    set("special_defense",(["evil":60,"energy":0,"fire":50,"cold":50,
                            "electric":50,"none":20]) );
    set("aim_difficulty",
    (["critical":-20,"vascular":80,"ganglion":20,"weakest":80]) );
    set("aiming_loc","weakest");

    set("inquiry",([
        "luoky":"@@ask_luoky"]) );
    set("exp_reward",20000);
        
    wield_weapon(TWEP"key2");
    equip_armor(TOBJ"shield1");
    equip_armor(TOBJ"arms");
    equip_armor(TOBJ"leggings");
}

int accept_item(object player,object ob)
{
    if( !ob || !(ob->query("give_to_sasami")) ) return 0;
    if( (string)ob->query("winner") != (string)player->query("name") ){
      tell_room(environment(),
"ɴɰ���е�ʧ����˵��лл������ͻ�����������������Ҷ���λ������ʿ˵��лл��\n"
"ɴɰ���������İ��ĳ���ػ����У�\n");
      return 1;
      }  
    if( (int)player->query_quest_level("find_luoky") < 1) {
    tell_object(player,"лл��Ϊ���һ��˻ʹ�лл��\n");
    tell_room(environment(),
       "ɰɴ���������İ��ĳ���ػ����У�\n");
       player->finish_quest("find_luoky",1);
    tell_object(player,
      "���Ѿ���������������õ�1000�㾭��ֵ\n");
       player->gain_experience(1000);
       ob->remove();
       return 1;
     }
     tell_object(player,"�ٴθ�л���İ�æ��лл����\n");
     tell_room(environment(player),
       "ɰɴ����΢Ц��"+player->query("c_name")+"�����ı�ʾ��л����\n"); 
     return 1;
 } 
 
 void ask_luoky()
 {
    write(@ALONG
�˻ʹ����������İ��ĳ�������е���С���ӣ���ֻ���䳤���ģ���������
è�������������Ժ��ȥ���ʱ����ͻȻ����ʧ�ˣ���Ը����Ұ����һ�����
���������˸����㣬Ҫ�����Ļ���һ��Ҫ���ܲ��������ܱ�Ŷ����Ȼ����ҧ��Ŷ��
лл�㣡��^_^
ALONG
        );
	return ;
}
void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}        
