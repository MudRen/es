#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "han"

inherit DAEMON;

int check_weapon(object me)
{
  object weapon;

  if (!me)
    return 0;

  if (!me->query_temp("gonfu_busy"))
    return 0;

  weapon=(object)me->query("weapon1");
  if( !weapon || (string)weapon->query("type") != ("longblade") ) {
           tell_object(me,"�㲢δװ���ʺϵ�������\n");
           tell_object(me,
             set_color("������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n","HIY")
             );

        tell_room( environment(me),
          me->query("c_name")+"������³�һ��������ʽ������\n"
           , me);

        me->delete("attack_skill");
        me->delete("defense_skill");
        me->delete_temp("gonfu_busy");
        return 0;
  }
  call_out("check_weapon",2,me);
  return 1;
}

int enhant(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");

        if( !weapon || (string)weapon->query("type") != ("longblade") ) {
           tell_object(me,"�㲢δװ���ʺϵ�������\n");
           return 0;
        }

	tell_object(me, 
		"\n�㿪ʼ��������춽���, ׼��ʹ����"+
		to_chinese(GONFU_NAME)+"��!!\n");

	tell_room( environment(me),
		"\n"+me->query("c_name")+
		"���һ���������ϵ�"+weapon->query("short")+
		"һ����׼��ʩչ���ѵ�һ����"+
                to_chinese(GONFU_NAME)+"��\n" , me);

	me->set("attack_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
        call_out("check_weapon",2,me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
        if (!me->query_temp("gonfu_busy"))
          return;
	tell_object(me, 
          set_color("������һ����, ֹͣʹ��"+to_chinese(GONFU_NAME)+"��\n","HIY")
          );
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"������³�һ��������ʽ������\n" , me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
