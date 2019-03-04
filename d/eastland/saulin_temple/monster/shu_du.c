#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "master shu du", "��ĦԺ��ϯ ���" );
        add ("id",({ "monk","master","shu","du"}));
        set_short("��ĦԺ��ϯ ���");
        set("unit","λ");
        set_long(@DESC
���Ǵ�ĦԺ��ϯ��ɴ�ʦ����Ȼ��ӵ�м��ص���ڳ��ף�������ʵ�����Ѿ����
��ʮ�ˣ���������ʱʱ����Ц�ݵ����ų�����������һ������ʹ�����ң�����
���ԣ�һ�����ޣ�Ⱥа�رܡ��ɼ�������������\��\��
DESC
        );
        set("alignment",1200);
        set("wealth/gold",50);
        set("max_hp", 950);
        set("hit_points", 950);
        set("max_fp", 2500);
        set("force_points", 2500);
        set("special_defense", ([ "all" : 40, "none" : 30 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60, ]) );
        set_perm_stat("str",29);
        set_perm_stat("int",25);
        set_perm_stat("dex",25);
        set_natural_weapon(-12,5,8);
        set_natural_armor(67, 25);
	set_skill("longblade",100);
        set_skill("parry",100);
        set_skill("block",100);
        set ("gender", "male");
        set ("race", "human");
	set("attack_skill",CLASS"burn_blade");
	set("gonfus/burn-blade",35);
        wield_weapon(SAULIN_OBJ"blade");
        equip_armor(SAULIN_OBJ"glove3");
        equip_armor(SAULIN_OBJ"shield1"); 
        equip_armor(SAULIN_OBJ"armband1");
        set("inquiry", ([
        "ȼľ����" : "@@ask_blade" ]) );
}

int ask_blade()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n��ɺȵ�����Ϊ������ɮ�����Ͻ�Э���һ�ʧȥ����Ͼ�������������ѧ�书��\n");
      return 1;            }

   if( me->query("monk_gonfu/burn-blade") ) {
      tell_object( me, "\n���˵����ѧ���˻���������̫��û�����ǰ�.....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus �� %d\n",gonfus);

   if( gonfus < 1 )
      tell_object( me, "\n�������˵����ȭ�Ź�������������ѧȼľ�������ٹ�һ�����...\n");
   else {
      tell_object( me, @MSG

��ɶ�����ϸ�ش���һ��.

����˵�������������������ȷ����ѧ����ȼľ������
          ���������۾�����ϸ���ã�
          
��ɻ����ؽ����޵��������˴���������ó��.....

���أ��������ʹ��ȼľ�����е���ʽ������һ�������ڿ��з���,
���ȵ���Ϣ���������������������ô���������....

ֻ�������һ����Х������ͷһ�����޵���ָס����ʺ�....

���Ц����С�ӣ�ȼľ���ɲ�����ͨ���书ร�û�����ӾͲ�Ҫ����ͷ���Ҷ�������...

������ɵ��˵�ͷ.

����յ�˵�����ã�С�ӣ����ȥ��....

MSG );
      me->set("monk_gonfu/burn-blade",0); }

  return 1;

}
