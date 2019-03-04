//#pragma save_binary

#include "../mage.h"

inherit ROOM;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Energy Room", "��Դ��" );
	set_long( @LONG
  NEED WORK HERE!
LONG
            , @C_LONG
���Ǵ���ħ����Դ�ĵط�����е�һ��ǿ���ħ���������������ר�˰�
�㲹��(recharge)ħ����������Դ�������м����Լ����֣�С�Ŀ��Ʋ�������
װ����
C_LONG
);
	set( "exits", ([ "down" : MAGE"library", ]) );
    set( "no_monster", 1);
	set( "objects", ([
	 "cid" : MAGE"monsters/cid", 
         "wand" : MAGE"weapons/little_wand",
	]) );
	reset();
}

void init()
{
    add_action("to_recharge", "recharge");
}

int to_recharge(string str)
{
    object item, who;
    int wc, damage, times, skill, karma, cost_money, cost_exp, money, exp;
    who = this_player();
    
    if( !str ) 
      return notify_fail( 
        "ʹ�ø�ʽ: recharge <��Ʒ����> \n" );
    if( !(item=present(str, who)) )
      return notify_fail("������û���������\n" );
    if( !item->query("max_charge") )
      return notify_fail( "�ⲻ��ħ����Ʒ���޷�����ħ����Դ!\n" );
    wc = (int)item->query("weapon_class");
    damage = (int)item->query("special_damage");
    times = (int)(item->query("max_charge"))-(int)(item->query("charge_left"));
    if( !times ) 
      return notify_fail("����Ʒ�ѳ�����ħ����Դ���㻹Ҫ�˷�Ǯ��?\n");
    skill = (int)who->query_skill("recharge");
    karma = (int)who->query_stat("karma");
    money = 200;
    exp = 500;
    cost_money = wc*damage*times*(150-skill)/money;
    cost_exp = wc*damage*damage*(130-skill)/exp;
    if( (int)who->query_exp_stock() < cost_exp )
      return notify_fail(sprintf("��������Ʒ����Դ����ʧ�� %d �㾭��ֵ������þ���ֵ���㡣\n",cost_exp));
    if( present("cid") && !who->debit( "silver", cost_money ) )
      return notify_fail(sprintf("��������Ʒ����Դ��Ҫ %d ���ҡ�\n" ,cost_money));
    who->gain_experience( -cost_exp );
    if( !present( "cid" ) ) {
      tell_room( this_object(), sprintf( "%s��%s������Դ��������档\n",who->query("c_name"),item->query("c_name")), who );
      tell_object( who, sprintf("��С������İ�%s������Դ��������档\n",item->query("c_name")));
      if( random(125) > skill || random(30) > karma ) {
        tell_room( this_object(), sprintf("����һ��С��%s���ɻҽ���ʧ�ˡ�\n",item->query("c_name")));
        item->remove();
      } else {
        tell_object( who, 
          sprintf("һ��ʱ��֮�ᣬ���%s���˳�������������������ħ����Դ��\n" ,
	item->query("c_name")));
        tell_room( this_object(), 
          sprintf("һ��ʱ��֮�ᣬ%s��%s���˳�������������������ħ����Դ��\n" ,
	who->query("c_name"),item->query("c_name")), who);
        item->set("charge_left",(int)item->query("max_charge") );
      }
    } else {
      tell_object( who, 
        sprintf("���%s����ʩ�ã�ֻ��������������Դ������С�\nһ��ʱ��֮�ᣬ���������˳������黹���㡣\n" ,item->query("c_name")));
      tell_room( this_object(), 
      sprintf("%s��%s����ʩ�ã�ֻ��������������Դ������С�\nһ��ʱ��֮�ᣬ���������˳������黹��%s��\n" ,
	who->query("c_name"),item->query("c_name"),who->query("c_name")),who );
      item->set("charge_left",(int)item->query("max_charge") );
      tell_room( this_object(), "ʩ��˵: ����ˡ�\n");  
    }
    return 1;
}
