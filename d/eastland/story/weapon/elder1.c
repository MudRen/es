#include "/d/eastland/story/story.h"

inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Wing Archelder Queen", "���" );
	add ("id", ({ "elder","archelder","queen"}) );
	set_short( "����������� ���");
	set_long(@CLONG
һ�������ܴ���������ˣ������������ݺᣬ����ҵ�ѵ����룬��򽥽��˻�ֻ
ʣ������ͻ��������������ձ�����·��һ��һ����ȫ��������ľ�Ȳ������Ȼ��
��ʹ�ͷ��������һ��Ҳ��������ƽʱ���Ϲ�����֮�����ḻ����˴�������
Ȩ�����ˣ�����Ϥ�����þ������ͬʱ�Ǹ����µ�ʩ���ߣ���ʹ��СС�ķ���һ��
�����б����������ƥ�������ǳ���
CLONG
	);
	set("gender","male");
        set("race","����");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", -1000000 );
	set( "hit_points", 1800 );
	set( "max_hp", 1800 );
        set( "max_fp",400);
        set( "weight",100);
        set_natural_weapon( 20, 15, 20 );
	set_natural_armor( 50, 28 );
        set("aim_difficulty",([ 
    	  "critical":80,"weakest":50,"vascular":40,"ganglion":50 ]) );
        set("wealth/gold",200);
        set("stun_difficulty",100);
        set_temp("bs",10);
        set_temp("be_joke",3);
        set("conditions/_heal_hp",({ 4 , 1 }) ) ;
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set_skill("elemental",100);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("wand",80);
        set("spells/lightning",2);
        set("spells/ether-bolt",6);
        set("spells/flare",2);
        set("spells/sleet",4);
        set("spells/fireball",6);
        set("spells/heart-griping",4); 
        set("guild_levels/black-magic",50) ;
        set("guild_levels/elemental",50);
        set("guild_levels/guild",50);
        set("tactic_func","my_tactic");
        set("magic_delay",3);
        wield_weapon(SWEA"imp_wand");
        equip_armor(SARM"imp_leggings");
        equip_armor(SARM"imp_cloak");
        equip_armor(SARM"imp_ring");
        equip_armor(SARM"imp_amulet");
        equip_armor(SARM"imp_cloth");
        set("special_defense",(["all":100,"none":40,"energy":-10]));
        set( "inquiry", ([
          "forbidden_ground":"@@ask_help",
                   "history":"@@ask_history",
             "great_vampire":"@@ask_vampire",
                 "fly_flute":"@@ask_flute",
              "flute_energy":"@@ask_energy"
        ]) );
        set("chat_chance",10);
        set("att_chat_output",({
              "���Ц�����֪���ߣ����˱���δ���п�ն���������������ˣ�\n",
        }) );
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
}
void ask_energy(object asker)
{
write(@LONG
���˵����������֮�ѡ�����Դ���ޣ�������֮�ѡ����ԡ�����֮ˮ��(heaven_water)
          Ϊ������Դ�ģ���춡�����֮ˮ���������һ��ͷ����û�У���ȥ��̸�
          �˰ɡ�
LONG
   );
}
void ask_flute(object asker)
{
   asker->add_temp("flute_asked",1);
write(@LONG
���˵�������ʡ�����֮�ѡ���ร����Ѿ�������������̳ǡ�֮��������������
�����������ˣ���ʹ��ҵĿ���ȥ����Ҫ�ɡ�   
LONG
);
}
void ask_vampire(object asker)
{
write(@LONG
���˵���������ȳ�����������Ľ�����������ǧ��ǰ�����շ������
��������������˵�����ֳ���Ϊ�����䣬������շ��������ǵ�һ����
�����������������ȳ���������������ԣ�Ωһ�µ��ǡ���ħ����(ghost
          -killed spell)���������շ�����������ǧ����࣬��Ҫ�ҳ�
          �����ܱ�Ǹ���Ҳ�֪�������Ƿ������䣬�㻹�Ƕ�ȥ��������
          ������������
LONG
   );
}
void ask_help(object asker)
{
   write(@LONG
���˵������˵�����Ǿ�ס����ı����и����أ���������ĳ�ֽ��ƣ�
������������Ҫ��������ף���ķ���ͨ������ȷ�����ݣ�����һ������
�����������޷����׵�����ȥ�ġ�˵������ף���ķ��ߣ������Ͼ���һ
�����������������������ǲ��������׸���ġ�
LONG
   );   
}
void ask_history(object asker)
{
   write(@LONG
���˵����ǧ����ǰ�����˱��ǻƵ�����һԱ�罫���ཨ�������������
������������׾Թ�϶���ָ�����ɱ��֮�࣬������ս��֮�ᣬ��׼��
�����������ϻ��磬�����԰����ս���ݲв������������ٵô˴��е���
����������������׼����ס�˹��˳��Ϊ��ۿ��ر������أ�ǧ��������
���������������漰���¡���춳���ס�ڵ��ϣ�������е�����Ҳ����ʧ
�����������ˡ���   
LONG
   );
}
int my_tactic()
{
    int i,k;
    object victim;
    
    string power,name;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10)> 1 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    k=1+random(2);
    switch ( k ) {
    case 1 :
        power="max";
        break;
    default : 
        power="normal";    
        break;
    } 
    name=victim->query("name");
    for ( i=0;i<k;i++ ) {
       switch ( random(6) ) {
         case 0:command(sprintf("cast %s fireball on %s",power,name));
                break;
         case 1:command(sprintf("cast %s sleet on %s",power,name));
                break;
     	 case 2:command(sprintf("cast %s flare on %s",power,name));
                break;
         case 3:command(sprintf("cast lightning on %s",name));
                break;
         case 4:command(sprintf("cast %s ether-bolt on %s",power,name));
                break;
         case 5:
                command(sprintf("cast %s heart-griping on %s",power,name));
                break;
         default :
                command("say �г��:~~\n");
                break;
       }
    }
//    set("stop_attack",0);
    return 1;
}
void die()
{
     set("alignment",2000);
     ::die();
}
