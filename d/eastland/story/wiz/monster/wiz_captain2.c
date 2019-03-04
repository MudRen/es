#include "../../story.h"

inherit MONSTER;
int atk=0;
void create()
{
	::create();
	set_level(18);
	set_name( "The captain of policeman Sha","�ĺ���" );
	add( "id", ({ "captain","sha"}) );
	set_short( "�����Ĵ����� �ĺ���" );
	set_long(@C_LONG
����ͳ���������̳ǡ��������в����ͷ�졣����Ŀ��䣬Ƥ���ֺڣ�������ӥ��
�ǡ������һ��ӥ�ۣ���Ŀ�������Ѽ����������ޱȡ��ĺ����������Ĵ�����֮
һ����Ϊ�������������ǿ���ǻ����򣬼���ı�ԣ��Ǹ��൱���µĶ��֣�������
�ڿ�ջ��С����Ƴ�Щ���������������Բ�����
C_LONG
        );
	set( "gender", "male" );
	set("unit","λ");
	set( "alignment", 400 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 28 );
        set_perm_stat( "int", 28 );
        set_skill( "parry", 90 );
        set_skill( "thrusting", 90 );
        set_skill( "dodge", 90 );
        set("wealth/silver",1000);
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp",400);
        set("weight",900);
        set("special_defense", ([ "all":100,"none":5,"evil":50]) );
        set("aim_difficulty",
            (["critical":60,"vascular":30,"weakest":30]) );
        set_natural_armor(58,28);
        set_natural_weapon(3,5,1);
        wield_weapon(SWWEA"captain_hook1");
        equip_armor(SWARM"captain_hat1");
        equip_armor(SWARM"captain_cloth1");
        set("tactic_func","my_tactic");  
        set("chat_chance",1);
        set("chat_output",({
            "�ĺ����������Ҫ������Ҫ��������ǵİ�ȫ�������ɱ�������� �ȳ���(great_vampire)����ȥ�ˡ�\n"
        }) );
        set("att_chat_output",({
          "�ĺ��̿�Ц���ߣ���ʹ��桸���� �ȳ���(great_vampire)�����ɣ�\n"
        }) );
        set( "inquiry", ([
          "great_vampire":"@@ask_vampire",
          "special_things":"@@ask_things"
        ]) );
}
void ask_vampire(object asker)
{
     tell_room(environment(),@LONG

�ĺ���˫Ŀ���������������С��ʱ��һ��ԭ���߸����˵�ǰ���⹫�Ұ��꣬
������������������������֪;��ͻ�����һ��������磬��������һ�������
�����������������������ֵĽ�����ֻһɲ�ǣ�ȫ�Һ��������ֻ������һ����
��������������������������������ȣ�ָ��ԭ�����Ǹ����꽩�������С��ȳ�
��������������������������ֱ�����ڣ�����Ȼ�������Ƕ�Ѫ�������ǰ����
����������������������̸�����ԶԶ�����������ƽ�����û���ǽ�����������
�������������������������񡸹ȳ��������������������޷�����ǰȥ��   

LONG 
   );
}
void ask_things(object asker)
{
    tell_room(environment(),"�ĺ���˵�����ر�Ķ������ҵ������ͺ��ر𰡡�\n");    
}
int my_tactic()
{
    object victim;
    int i,k;
    
    if( (!victim=query_attacker())||atk||(random(20)>1) ) return 0;
    tell_room(environment(),set_color(sprintf(
       "�ĺ��̷��������������Ӿ���ض������˷�������������\n"),"HIW"));
    atk=1;
    k=2+random(2);
    for (i=0;i<k;i++)
      this_player()->continue_attack();
    atk=0;
    return 1;
}
