#include "../iigima.h"
#include <stats.h>
#include <conditions.h>
// Created by Iigima , modified by Smore@Eastern.Stories in 8/20/1996
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Salin","�������" );
        add ("id", ({ "drow","salin" }) );
        set_short( "Salin","�������" );
        set("unit","λ");
        set("alignment",1100);
        set("weight",800);
        set("wealth/copper",4000);
        set( "weight", 600 );
        set( "tactic_func", "my_tactic" );
        set_long(
@C_LONG
��λ�ϸ����Ǻڰ�������쵼�ߣ������������������������ˣ���
��һ���߸ߵ�ñ�ӣ������Ҳ����һλ��˾�ɣ��º͵��۹�����¶��
���ߵķ緶������ڰ������Ҫ��Ů��˾�������� (god)����������
Ϊ��æµ����
C_LONG
        );
        set_perm_stat("int", 25);
        set_perm_stat("dex", 16);
        set_perm_stat("str",18);
        set("max_hp",550);
        set("hit_points",550);
        set_natural_weapon( 10, 10, 20 );
        set_natural_armor( 25, 20 );
        set( "special_defense", ([
                "all":30,"fire":-10,"cold":-10,
                "evil":80,"divine":-50,"none":20
                        ]) );
        set ("race", "drow");
        set ("gender", "female");
        set_c_limbs(({"����","ͷ��","�Ų�"}));
        set( "chat_chance", 14 );
        set( "chat_output", ({
           "���һ����ɫ�������кܶ����š�\n",
           "����˵���÷�ร����벻�ܻķϣ����Ǵ����ֲ��½�.....\n",
           "����૵�˵������õ����Ѳ�(snake herb)��һ�оͺð���...\n"
                          }));
        set( "inquiry", ([
        "god" : ({
"��...���������Ǻڰ�����Ĵ�ͳ��ÿ�궼Ҫ����һλŮ��˾��˾�ȿ�Ů��\n"
                }),
        "teeder" : ({
"�ٵ�����Ҳ֪�������˶��������������������Ǽ�˾������������أ�\n"
               }),
        "snake herb" : ({
"���Ѳݣ��������Ѳ�����������ҩ(drug)�Ĺؼ�Ү��\n"
              }),
        "drug" : ({
"�ţ�����������һ���ܷ�ֹ����֮�ص�����(snake)�������Ǵ����ҩ��\n"
"���Ǿ��Ƕ�ȱ�����Ѳݣ�����������ҩ��������⣡\n"
                 }),
        "snake" : ({
"���ܰ����õ����Ѳ��𣿵��ǽ���֮���ǲ��ܽ�ȥ�ģ������Σ��\n"
"��...��˵�и�ð�ռ�(adventurer)..��������ȥ������֮��......\n"
                 }),
        "adventurer" : ({
"�������ʲ��ģ���ȥ���Ұɣ���Ҳ����ʶ�����Ү��\n"
                 })
            ]) );
   wield_weapon( OBJ"wand" );
   equip_armor( ARM"robe" );
   equip_armor( ARM"lucky_cloak" );
   equip_armor( ARM"lucky_shoes" );
   equip_armor( ARM"lucky_ring" );
}
int accept_item(object me, object item)
{
   string name;
   object ob;
   int i;

   name=(string)item->query("name");
   if (!name || (name!="snake herb"))
     return 1;
write("����˵����̫���ˣ��Ҿ���Ҫ�����Ѳݣ�лл��������Ǵ���\n");
write("���������ĳ������������ң�����Ҫ�ó�ʲ�ᶫ��......\n");
   if (!this_object()->query("key")){
     write("����˵�����ţ���Կ�׸���ɣ�����Щ���Ѳݸ���ร���\n");
     ob = new( OBJ"key" );
     ob->move(this_player());
     set("key",1);
   }
   else
write("������ֻ���˵�����������˽����ȵ��ˣ�Կ���Ѿ�û���ˡ�\n");
   return 1;
}
int my_tactic()
{
   object *victim,env;
   int i,n;
   env=environment(this_object());
   if ( !victim = query_attackers() ) return 0 ;
   if( random(20)>4 ) return 0;
    else {
    tell_room( environment(this_object()),
    "���ֻ������к�ħ���пֺ���������: ɳ���̣���˹����.....\n"
            "�㷢��һ����������������ϣ������ʶ����ģ��...\n\n",
     this_object() );
      for( i=0; i<sizeof(victim); i++ ) {
      n = i + 1;
      if( n == sizeof(victim) ) n = 0;
      (CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5);
  if( sizeof(victim) == 1 ) {
      tell_room( env,
      victim[i]->query("c_name")+
      "ͻȻ��ʼ����"+victim[n]->query("c_name")+"��\n",
          victim[i]);
      victim[i]->cease_all_attacks();
      victim[i]->kill_ob(victim[n]);
  }
      return 1;
 }
 }
}
