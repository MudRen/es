#include "../tsunami.h"
#include <stats.h>

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name("General Kagado","���佫�� ������");
    add("id",({"general","kagado"}) );
    set_short("�����˽���");
    set_long(@LONG
���佫����������Ŀǰ����ħ�������ָ�ӹ٣�ֱ�������������¡�������ˣ�
��ĸߴ���䣬��С�˺�������������Ѿ���������Сս���������ˡ����˶����һ�
���ҳϣ�ֻ��Ҳ��һ���ǳ�Ҫ���õ�ȱ�㣬���ǰ�������������ֻҪ��Ǯ�������ϰ�
æ������˵��й¶�ʳǵ�ͨ������ѽ.....�ȵ�֮��ģ���Ȼ���ѹ����⣡
LONG
            );
    set("unit","λ");
    set("gender","male");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);
    set_natural_armor(30,30);
    set_natural_weapon(5,15,17);
    set_perm_stat("str",20);
    set_perm_stat("dex",20);
    set("max_hp",800);
    set("hit_points",800);
    set_skill("parry",80);
    set_skill("longblade",100);
    set_skill("block",80);
    set("wealth/gold",200);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",(["critical":80,"vascular":10,"ganglion":40]) );
    set("exp_reward",15000);
    set("inquiry",([
         "password":"@@ask_passwd"]) );    
    wield_weapon(TWEP"sword1");
    equip_armor(TOBJ"shield2");
    equip_armor(TOBJ"helmet1");
    equip_armor(TOBJ"boot1");
    equip_armor(TOBJ"chainmail");
}

void init()
{
    add_action("do_pay","pay");
}

int do_pay(string str)
{
    string who, type;
    int num;
    if( !str || str=="" || sscanf(str, "%s %d %s",who, num, type) !=3)
    return notify_fail("��˭?����Ǯ��\n");
    
    if(!id(who)) return 0;
    
    if(type != "copper") {
    tell_object(this_player(),
    "�����˽����Բ�м�Ŀ���˵�����Ƕ�ֻ֪���ý�ģ�����....��ƫƫ��Ҫͭ������\n");
    return 1;
    }
    
    if( !this_player()->debit(type, num)){
      write(
      "�����˽���ŭ����Ǯ���������������ˣ�����һ���ȥ��\n");
      tell_room( environment(this_player()),
      "����ͻȻ�������ң���"+this_player()->query("c_name")+"���˳�ȥ��\n"
      ,this_player() );
      this_player()->move_player(CITY"sway3","SNEAK");
      tell_room( environment(this_player()),
      "�ۡ�����ͻȻǰ��һ�ź�Ӱ���£�Ŷ������ԭ����"+this_player()->query("c_name")+"�������˳�������\n"
      ,this_player() );
      return 1;
    }
    if(num < 500){
    write("�����˽����ɴ����۶��������Ǯ����С������Ŷ����\n");
    return 1;
    }
    if(num >= 500){
    write(@BLONG
�����˽���Ц�����˵��С�ӣ�����ǰ;������Ŷ����
                      ����ϸ�ˣ�ֻ˵һ��............
                      �ܾúܾ���ǰ��һ���Ϲ�����һ��������........

���쳤��������ϸ������............
BLONG
               );
    this_player()->set_temp("block_command",1);  
    call_out("leave",5,this_player());
    return 1;
    }           
}    
    
int leave()
{
   write(@CLONG
�����˽���ͻȻ����������˵�������ˣ������°ɣ���
CLONG
        );
   this_player()->set_temp("block_command",0);
   this_player()->set_explore("island#3");
   return 1;     
}   

int ask_passwd()
{
    write(@CLONG
�����˽���˵����ͨ�����룿��Ȼû����ѽ........
˵��˵������ת���⣬ټ�������̯������ǰ��ѽ�εģ���֪������������.......
CLONG
         );
    return 1;
}          
