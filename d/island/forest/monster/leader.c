#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Emperor Yuishu","ң��");
    add("id",({"emperor","yuishu"}) );
    set_short("ң�����");
    set_long(@C_LONG
ң�������Ȼ���һ����ˣ�����ȴ�����о���ֻ�������˰�ľ��������
�Ļ�����������ʮ�ֵ����š��ס�������ϸһ�����⵶���������д�ҷ緶
��ֻ�������β�����ʮ�����ɣ������жȣ�һ�����ߵķ緶£��������ȫ��
�����ֱ�������㣺����λ��ƽ�������
C_LONG
            );
    set("unit","λ");
    set("gender","male");
    set("race","daemon");
    set("alignment",-2000);
    set("class","scholar");
    set("time_to_heal",10);
    set_natural_armor(85,40);
    set_natural_weapon(80,30,45);
    set_perm_stat("str",25);
    set_perm_stat("dex",30);
    set_perm_stat("int",30);
    set_perm_stat("kar",30);
    set("max_hp",800);
    set("hit_points",800);
    set("max_fp",1000);
    set("force_points",1000);

    set("attack_skill",CLASS"han");
    set("scholar_gonfu/han",30);
    set("scholar_gonfu/poem",30);
    set("scholar_gonfu/song",30);
    set("scholar_gonfu/tang",30);
    
    set_skill("parry",100);
    set_skill("tactic",100);
    set_skill("dodge",90);
    set("tactic","melee");
    set("wealth/gold",500);
    set("aim_difficulty",(["critical":100,"vascular":100,"ganglion":20,
    "weakest":0]) );
    set("special_defense",(["evil":60,"fire":50,"cold":60,"energy":60,
                            "electric":80,"none":40]) );
    set("exp_reward",37000);
    
    set("chat_chance",20);
    set("att_chat_output",({"\nң�մ�ȣ�С�ӣ�����ǡ��������������۾������ˣ�\n\n"}) );
    call_out("myskill01",25);
    
    wield_weapon(TWEP"sword2");
    equip_armor(TOBJ"cloth2");
    equip_armor(TOBJ"skirt2");
    equip_armor(TOBJ"feet2");
    equip_armor(TOBJ"ring1");
    equip_armor(TOBJ"amulet1");
}

void myskill01()
{ 
  delete("att_chat_output");
  set("att_chat_output",({"\nң������һת������ʫ������һ��һ�еݽ�������\n\n"}));
  delete("attack_skill");
  set("attack_skill",CLASS"poem");
      call_out("myskill02",25);
 } 
 void myskill02()
 {
   delete("att_chat_output");
   set("att_chat_output",({"\nң�ռ�Ц������ʶ��ʶһ�¡��δʽ������ɣ�\n\n"}));
   delete("attack_skill");
   set("attack_skill",CLASS"song");
   call_out("myskill03",25);
}
void myskill03()
{ 
    delete("att_chat_output");
    set("att_chat_output",({"\nң��ͻȻ������˵�������á���ʫ���������д����µ�����ɣ�\n\n"}));
    delete("attack_skill");
    set("attack_skill",CLASS"tang");
    call_out("myskill04",25);
}    

void myskill04()
{
    delete("att_chat_output");
    set("att_chat_output",({"\nң�մ�ȣ�С�ӣ�����ǡ��������������۾������ˣ�\n\n"})); 
    delete("attack_skill"); 
    set("attack_skill",CLASS"han");  
    call_out("myskill01",25);
}  
