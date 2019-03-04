#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Shan chi", "������ɮ" );
        add ("id", ({ "monk","shan","chi" }) );
        set_short( "Shan chi","������ɮ");
        set("unit","λ");
        set_long("",@C_LONG
�����������½�����λ���ֱ��ĳ���֮һ��Ҳ��ǰ���εķ��ɡ�����
���ʱ��ϲ��ϰ�䣬�����͵ľ����񹦺��׽������Ȼ�������֡�����
�������Ѿ����������ˣ�����ż�������������ش��ʵ�ʱ�������Σ
���⣬ƽʱ������ָ�����ֹ��ᡣ
C_LONG
        );
        set("exp_reward",50000);
        set("alignment",2000);
        set("wealth/silver",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",2000);
        set("force_points",2500);
        set("max_hp",2000);
        set("max_fp",2500);
        set_perm_stat("str",30);
        set_perm_stat("dex",26);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",29);
        set_perm_stat("int",25);
        set_natural_weapon(35, 14, 30);
        set_natural_armor(90, 30);
        set_skill("dodge",100);
        set_skill("blunt",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        set("attack_skill","monk/general/king_kong");
        set("monk_gonfu/king-kong",35);
        wield_weapon("/d/monk/guild/weapons/kingkong_staff");
        equip_armor("/d/monk/guild/armors/sandal_beads");
        equip_armor("/d/monk/guild/armors/damo_plate");
        equip_armor("/d/monk/guild/armors/god_armband");
        equip_armor("/d/monk/guild/armors/holy_ring");
        equip_armor("/d/monk/guild/armors/cloud_boots");
        set("inquiry", ([
        "brassman" : "@@ask_brassman",
        "����" : "@@ask_return",
        "֤��" : "@@ask_proof",
        "����ȷ�" : "@@ask_staff" ]) );
}

int ask_staff()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n�������ĵ�˵��������ʧȥ����Ͼ���δѰ�أ�Ŀǰ��ʵ�������Ծ��������úõش������书\��\n");
      return 1;            }

   if( me->query("monk_gonfu/king-kong") ) {
      tell_object( me, "\n����˵�����㲻���Ѿ�ѧ�����𣿸�Ҫ�ú���ϰ����....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus �� %d\n",gonfus);

   if( gonfus < 2 )
      tell_object( me, "\n�����º͵�˵������Ҫѧ������, ���Ȱ�ȭ������������...\n");
   else {
      tell_object( me, @MSG

���ȺͰ����������ͷ.

����˵�����ѵã��ѵã���������������ȷ�����ʸ�������ȷ���
          ��������������һ�θ��㿴�ɣ�
          
���Ȼ����ؽ�����Ⱦ���˫����¶���ֺ������......

ͻȻ����������ʹ������ȷ��е���ʽ��ֻ��һ����Ӱ�ڿ��з���,
ʱ��һ�����Ľ��͸Ӱ����, ��������......

��һʱ, ��Ӱ������, �����������ȵ���ò....

����ЦЦ�ض���˵���ú������˽�����

����˵�ͷ.

���ȺͰ����������ͷ˵��������ȷ����������Σ�ʹ��ʱҪ�Ĵ�����źð���

MSG );
      me->set("monk_gonfu/king-kong",0); }

  return 1;

}

int special_attack()
{
    object victim;
    int fp;
    
    if(random(20)>7) return 0;
    victim = query_attacker();
    if( !victim ) return 0;
    fp=(int)victim->query("force_points");
    tell_room(environment(victim),
"\n������������񹦣�һ�����������Ե���ӿ��˫�֣���"+
(string)victim->query("c_name")+"ֱ���ȥ��\n",victim
	);
    tell_object(victim,@C_LONG
    
������������񹦣���ʱ�㱻һ��ǿ���������������ͻȻ��ɾ���ֱ��
��ĵ���������ľ����ƺ��Ѿ����ˡ�

C_LONG
    );
    victim->receive_damage(60-random(fp/10));
    return 1;
}

int ask_brassman()
{
	object obj;
	obj = this_player();
	
	if( !obj->query("18brass") ) {
		tell_object(obj,
			"���� ����˵�����й�ͭ��������飬�����ȥ��̻�Ԫʦֶ��\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"���� ����˵��������ͨ��ͭ�����ˡ�������������( ���� )���ǵõ�һ��\n"
			"	       ( ֤�� )�� ?\n" );
		return 1; }
}

int ask_return() 
{
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"���� ����˵��������ͨ��ͭ������˵�ɡ�\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"���� ���Ͽ�����һ���.............\n\n\n"
			"ͻȻһ��������Ĺ�ͷ�ϴ���һ�� !!\n"
			"���� ����˵���������ӷ𣬶������ٶ�׹��쳾��������ǧ����֮�࣬\n"
			"	       ���˰���.....\n" );
	c_msg = set_color("[���ֺ���] ���� ��ɮ: ","HIC");
		c_msg += "���� "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "��Ϊ�����׼ҵ��� !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",1); 
	return 1; } 
	return 0;
}		
		
int ask_proof() 
{	
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"���� ����˵��������ͨ��ͭ������˵�ɡ�\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"���� ����΢Ц��˵����������ͨ����ʮ��ͭ��������ۻ�������ͨ��\n"
			"	             �����֤�� !!\n" );
		new("/d/eastland/saulin_temple/brass/obj/armband")->move(obj);
	c_msg = set_color("[���ֺ���] ���� ��ɮ: ","HIC");
		c_msg += "���� "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "ͨ��ʮ��ͭ����Ŀ��� !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",2); 
	return 1; } 
	return 0;	
}	
