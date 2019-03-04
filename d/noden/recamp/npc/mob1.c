
#include <mudlib.h>
#include "../camp.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "book fool", "�����" );
        add ("id",({ "book","fool","book fool" }));
        set_short( "�����");
        set("unit","λ");
        set_long(
@C_LONG
�������壬Ǭ��Ī�⣬Ц��Ӣ�ۣ�������������ӡ�
�����ƻã��Ʋ��ܹ�ޱ����ͣ����������н���
ѧ��Ž���֪���ģ���֪����һĿʮ�У���Ŀ������
��һҳ������ɵ�����ӣ�ȴ͸©��Ѱ����ʲ�������....
��������������ģ��ȡ�����廹���Խ���Ա���Ϊ����ӡ�
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 30, 20 );
	set_natural_weapon(25,5,15 );
	set("hit_points",300);
	set("max_hp",300);
	set( "wealth/silver",1000);
        set("aim_difficulty",
          (["critical":50,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("weight",500) ;
        set_skill("dodge",60) ;
        set_skill("parry",70) ;

}

int accept_item(object who,object item)
{
  int code;

  if ( !item->query_inked() ) {
    tell_room( environment(), 
      "�����̾�˿���: �󱿹ϣ�û�õĶ���Ҳ��������\n");
      command("give paper to "+who->query("name"));
      return 1; 
  }
  if ( (int)who->query_quest_level("lulu") >=1 ) code=1; else 
  if (who->query_temp("lulu_active")) code=2; else code=3 ;  

  if (code==3)
  write("�����˵:��..��������������˵��.......\n"
        "Զ��ʱ��, ��ԭ�ϵİ����˲���, ����һλӢ���������ķ(Gammu),\n"
        "����ˮ�����ס�����λ���Ὣ��������, ������ķ����ʱ��λ����\n"
        "�����Ů��¶¶(lulu), ��λ����Դ׵Ľ���, �Ӵ˲��ϵķ�����ͻ\n"
        ", ͻȻ��һ�����罫��������һȺ���صĶ���ɱ��, ���������׵�\n"
        "չ���Ҳ��̶ĵ���ɱ�ж�, �����˵ĺ���������, ��춻��˵о�, ��\n"
        "�������۵����罫�������Լ���������ע, ʩչ���µĺ�ħ��, ��ȫ\n"
        "�����˶����ʯͷ .....���ֲ�����¶¶ֻ���Ƚ����Ｐ�¼�ʼĩ��\n"
        "¼�ʯ����... ������: �����͡����������ڰ���쬿���ҽ����\n"
        "Ҽ�����������ˡ��˶�ҭ���֡������ط���Ϊ....\n"
        "ͻȻһ��ҫ�۵Ĺ�â���������㼸�����������ǰ�Ķ���......\n"
        "\n"
        "\n"
        "....\n"
        "\n") ;

  command("give paper to "+who->query("name"));

  write("�ף��㲻�������Լ��ǲ����ۻ���...������ǰ���˸�İ����Ů�ӣ�\n") ;
  tell_room( environment(), 
     sprintf("¶¶��%s(%s)��ͷ΢Ц��˵��: лл��\n",
     who->query("c_name"),who->query("name") ), who ) ;

  if (code>=2) 
    tell_object( who,"¶¶��ͷ΢Ц��˵��: лл������Ϊ��Ѱ���ҵĽ�����!!\n");

  if (code==3) { 
    who->set_temp("lulu_active",1);
/*
    tell_object( who, 
       "[�㿪ʼ�� ¶¶(lulu) ���񣬵õ� 1000 �㾭��]\n"
       );
    who->gain_experience(1000);
*/
     if( who ) who->set_explore("noden#38");
  }

   if( present("lulu", environment(this_object())) )
   {   this_object()->remove();
       return 1;
   }

  set("alt_corpse",CAMPMOB"lulu") ;
  die() ;
  return 1;
}
void die()
{
   ::die(1) ;
   return;
}
