#include "../mad.h"
#include <ansi.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "elder Guo", "������" );
        add ("id", ({ "elder", "guo" }) );
        set_short( "������" );
        set("unit","λ");
        set_long(@C_LONG
�㿴��һλ���봹��, ��ɫ��������ĸ������ߡ��ഫ�������ʮ����ʱ,
����Ų�벽, ���Ծ���춴���Σ��֮��, ������ҹ֮��, ��������춶���
�����������˿���η�ġ�ŭ��������������ʮ��ǰ, ������Ϊ�˴������
���ϵ�, ���������һ��, ƾ��һ������, ��������׷ɱ֮��������!
C_LONG
        );
        set("alignment",1200);
        set("wealth/copper",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",850);
        set("force_points",2500);
        set("max_hp",850);
        set("max_fp",2500);
        set_perm_stat("str",25);
        set_perm_stat("dex",30);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",22);
        set_perm_stat("int",28);
        set_natural_weapon(30, 12, 28);
        set_natural_armor(100,50);
   set( "special_defense", ([ "all": 60, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":25,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",50 );
        set_skill("dodge",100);
        set_skill("shortblade",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        wield_weapon( IANOBJ"flute" );
        set("inquiry", ([
          "hsin" : "����!?�Ϸ�����δ����������.....\n"
                   "��˵������������Ĵ�½֮��, �����˲���ͽ��ͽ��!\n",
          "burglar" : @C_LONG
ԼĪ����֮ǰ, ����ͻ��һ�ɻ���, ���ִݲ��޹�
��Ů, �����\���й�Ů֮�˼ҷ׷�Ǩ��˴�, ���±���������
�������Ϸ����׷������ʱ, �������ŷ����, ��������! ����
, �Ϸ��Ѱ�ķ�, ���ܲ�׽�����д���������, �������ֻ�����
��! �Ϸ����Ĺ�����ҹ��̸ϻ�, ���Ѳ��--��̾��Ȼһ������
������\С������������(trace),��ȥ�������ɡ�
C_LONG
        ]) );
}

void init()
{
   npc::init();
   add_action( "inform_me", "inform" );
}

int inform_me(string arg)
{
   object hero;

   hero = this_player();

   if( !arg || ( arg!="elder" && arg!="guo" ) )
        return notify_fail( "��Ҫ֪ͨ˭��?\n" );
   if( (int)hero->query_quest_level("iywolf")<1 ) {
        if( !hero->query_temp("kill_ian_devil") )
        return notify_fail( "������ҡͷ��: ȥ! ȥ! �Ϸ�û������˵��...\n" );
        tell_object( hero, @OK
������̾��: ԭ����ħ���ǹ��ϵĻ���! �޹ֺ�С÷��С��
֮���������ⶾ�� ........
��л������Ϊ���弰���ϳ�ȥһ�󺦡��Ϸ����������ʮ��
��֮л��, ������һ�㱡��, ����Цګ��

[ �����Ϸ��䵹���ҳ�һ��Ǯ�ҽ����� ]
[ ������ˡ������֮�ǡ�������, �õ���ǧ�㾭��ֵ ]
OK
        );
   if( (string)hero->query("class")=="adventurer"
     && (int)hero->query_level()> 4 )
   tell_object( hero,
        "�ޣ�������ˣ�����������ȥ��С�Ž���ĳ������(skill)��\n" );
        hero->finish_quest("iywolf",1);
        hero->gain_experience(8000);
        hero->credit("copper",5000);
        return 1;
   }
   write(
"������΢Ц��: ����, ������Ϊ, �Ϸ���о���,\n"
"�������С����, ʵ��û�ж��ŵ�Ǯ�����ˡ�\n" );

   return 1;
}

int special_attack()
{
   object *victim, *weapon1, *weapon2;
   int i, num;
    
   victim = (object *)this_object()->query_attackers();
   weapon1 = victim->query("weapon1");
   weapon2 = victim->query("weapon2");
   num = sizeof(victim);

   if( !victim || random(20)<15 ) return 0;

   if( num == 2 ) {
     tell_room( environment(this_object()),
        "\n�����Ͽ�ʼ���ࡺŭ��������֮�����κ��ˡ�........\n\n"
        "һ�����ε�����Ϯ���������!!\n\n",
     this_object() );
     (CONDITION_PREFIX + "confused")->apply_effect( victim[1], 6, 10 );
     (CONDITION_PREFIX + "confused")->apply_effect( victim[0], 6, 10 );
     victim[1]->block_attack(10);
     victim[0]->block_attack(10);
     victim[1]->set_temp("msg_stop_attack", 
        "( �㱻һ�����ε�������ס, �޷������� )\n" );
     victim[0]->set_temp("msg_stop_attack", 
        "( �㱻һ�����ε�������ס, �޷������� )\n" );
     return 1;
     }

   if( num == 3 ) {
     tell_room( environment(this_object()),
        "\n�����Ͽ�ʼ���ࡺŭ��������֮���Ʋ�������........\n\n"
        "���Ǿ��������ع���ͬ��!!\n\n" );
     victim[1]->cease_all_attacks();
     victim[2]->cease_all_attacks();
     victim[0]->cease_all_attacks();
     victim[1]->kill_ob(victim[2]);
     victim[2]->kill_ob(victim[0]);
     victim[0]->kill_ob(victim[1]);
     return 1;
     }

   if( num > 3 ) {
    for( i=0; i<sizeof(victim); i++ ) {
     tell_object( victim[i],
        "\n�����Ͽ�ʼ���ࡺŭ��������֮����ɽ������........\n\n"
        "���Ǳ�һ�����˳�ײ, ��������, �ɳ�����!!\n\n" );
     if( victim[i]->query("weapon2") ) {
        weapon2[i]->unwield();
        weapon2[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        weapon1[i]->unwield();
        weapon1[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        }
     if( !victim[i]->query("weapon2") && victim[i]->query("weapon1") ) {
        weapon1[i]->unwield();
        weapon1[i]->move(environment(this_object()));
        victim[i]->calc_weapon_class();
        }
     }
    for( i=0; i<sizeof(victim); i++ ) {
        victim[i]->receive_special_damage("energy",100);
        victim[i]->move_player(IAN"hamlet_path2",
                   "�㱻�������!\n", "һ�ź�Ӱ�ӱ���������ˤ��!\n" );
        }
    return 1;
   }
   return 1;
}

int accept_item(object who,object item)
{
   if( item->id("corpse") ) {
     tell_room( environment(this_object()),
        "�����ϵ�: �Ϸ���Ȼ�ᰮ�ղ���Ʒ, �����廹������!\n"
        "[ ������˵��˵���Ͱ�"+item->query("c_name")+"���ڵ���! ]\n"
        , this_object() );
     item->move(environment(this_object()));
     return 1;
     }
   tell_room( environment(this_object()),
        "�����ϵ�: ��л! �Ϸ���ϲ���ղ���Ʒ!\n"
        "[ ������˵��˵���Ͱ�"+item->query("c_name")+"��������! ]\n"
        , this_object() );
   item->remove();
   return 1;
}

void die()
{
   object *flute, pipe;

   flute = children( "/d/eastland/ianyeu/obj/flute" );
   pipe = present( "flute", this_object() );
   if( sizeof(flute ) > 1 ) {
        tell_room( environment(this_object()),
		"�����ϴ��һ��: ��! �Ҳ�����! ������Ҫ�ҵ�������±��Ӱ�!\n"
		"�����ϰ��������Լ������ಢͬʱ�۶�����!\n",
                this_object() );
        pipe->remove();
   }
   ::die();
}