//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_EMBATTLE_DIR "/d/scholar/embattle/"
#define SCHOLAR_EMBATTLE_SKILL "embattle/"

inherit DAEMON;

int help();

void delete_effect(object man,int ac_effect,int db_effect,int wc_effect)
{
  if (man) {
    if (man->query_temp("embattle_busy")) {
      man->delete_temp("embattle_busy");
      man->set_temp("extra_ac/body",(int)man->query_temp("extra_ac/body")-ac_effect);
      man->set_temp("extra_db/body",(int)man->query_temp("extra_db/body")-db_effect);
      man->calc_armor_class();
      man->set_temp("extra_wc",(int)man->query_temp("extra_wc")-wc_effect);
    }
  }
}

void delete_embattle_effect(object me)
{
  int i,ac,db,wc;
  object *party;

  party=me->query_temp("embattle_party");
  ac=(int)party[0]->query_temp("embattle_ac");
  db=(int)party[0]->query_temp("embattle_db");
  wc=(int)party[0]->query_temp("embattle_wc");
  for(i=0;i<sizeof(party);i++)
    delete_effect(party[i],ac,db,wc);
  return;
}

void check_eight(object me,string other)
{
  int member=0,i;
  object leader,*total_party;

  if (!leader = present(other,environment(me))) {
     tell_object(me,"ι !! ��������Ҫ��˭���� ?\n");
     return;
  }
  if (me->query_temp("other_party_leader")) {
    tell_object(me,"�����ھͿ��Է��������������ˡ�\n");
    return;
  }
  if (me->query_temp("depend_on_eight")) {
     tell_object(me,"������Ҫ���������������ơ�\n");
     return;
  }
  if ((string)leader->query_temp("leader") != (string)leader->query("name")) {
     tell_object(me,"��������һ������쵼�˺���������������ҡ�\n");
     return;
  }
  if ((string)leader->query("class")!="scholar") {
     tell_object(me,"Ҫʩչ����������������һ�������쵼�Ķ������\n");
     return;
  }
  if ( (string)me->query_temp("leader") != (string)me->query("name")) {
     tell_object(me,"�� �� �ֲ������쵼��ս����ʲ�������� ...\n");
     return;
  }
  if( (int)me->query("stop_attack")>0 ) {
     tell_object(me,"( ����һ��������û����ɣ��޷����� )\n");
     return;
  }
  for( i=0;i<sizeof(total_party=(mixed *)me->query_temp("party_members"));i++ )
     if(total_party[i]) {
        if (environment(total_party[i]) == environment(me))
           member++;
     }
  if (member!=4) {
    tell_object(me,"��Ķ��鲻���ĸ��˻��������������\n");
    return;
  }
  leader->set_temp("other_party_leader",me);
  me->set_temp("depend_on_eight",leader);
  tell_object(leader,(string)me->query("c_name")+"�����γɰ���������ϵ��\n");
  tell_object(me,"����������������ɡ�\n");
  return ;
}

void party_disband(object me)
{ 
  object other;

  if (other=me->query_temp("other_party_leader")) {
    other->delete_temp("depend_on_eight");
    me->delete_temp("other_party_leader");
    tell_object(me,"�⿪����������������ϵ��\n");
    tell_object(other,"�⿪����������������ϵ��\n");
  }
  else if (other=me->query_temp("depend_on_eight")) {
    other->delete_temp("other_party_leader");
    me->delete_temp("depend_on_eight");
    tell_object(other,"�⿪����������������ϵ��\n");
    tell_object(me,"�⿪����������������ϵ��\n");
  }
  else
    write("��Ҫ��ɢɶ ?\n");
  return; 
}

int cmd_embattle(string str)
{
        mapping check1;
	object me,victim,target;
	string name,who,*check2,other,disband;
        int flag;

        if( !str ) return help();

        me=this_player();

	if (sscanf(str,"%s at %s",name,who) != 2) {
          if (sscanf(str,"eight with %s",other) != 1) {
            if (sscanf(str,"eight %s",disband)==1) {
              if (disband=="disband") {
                call_out("party_disband",0,me);
                return 1;
              }
              else 
                return help();
            }
            else
              return help();
          }
          else {
            call_out("check_eight",0,me,other);
            return 1;
          }
        }

	if (!me->query(SCHOLAR_EMBATTLE_SKILL+name)) 
                return notify_fail("�ף���������������\n");

	if (!(victim = present(who,environment(me))))
		return notify_fail("ι !! ��Ҫ��������ҲҪ�Һö���� !!\n");

        if ( victim->query("user") ) {
            if( !member_group((string)me->query("name"), "admin") &&
                    (victim->query_level()<5 || me->query_level()<5) )
            return notify_fail("�ڶ����������弶���µ���Ҳ�׼ PK �� PK ���ˡ�\n");
        }

        if ((int)victim->query("no_attack"))
            return notify_fail("����������������������ɱ���ǲ���ɱ !!\n");

	if ( (string)me->query_temp("leader") != (string)me->query("name"))
		return notify_fail("�� �� �ֲ������쵼��ս����ʲ�������� ... û��������ܰɡ�\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( ����һ��������û����ɣ��޷����� )\n");

	if( environment(me)->query("no_embattle"))
		return notify_fail( 
			"����׼������ʱ����Ȼ���������Ǹ���������ľ��ء�\n");

        if( me->query_temp("embattle_busy") ) {
          if( !me->query_attacker() )
            delete_embattle_effect(me);
          else if( member_array(me->query_temp("embattle_victim"),me->query_attackers(),flag)==-1 )
            delete_embattle_effect(me);
          else 
            return notify_fail("��Ŀǰ��æ���ƶ����ƣ�û���������顣\n");
        }

        switch(name) {
        case "eight" :
          call_out("check_party",0,me,victim);
          break;
        default :
          (SCHOLAR_EMBATTLE_DIR+name)->start_embattle(me,victim);
          break;
        };
	return 1;
}

int check_party(object me,object victim)
{
   if (me->query_temp("depend_on_eight"))
     return notify_fail("�����ڱ������һ���������ơ�\n");
   if (!me->query_temp("other_party_leader"))
     return notify_fail("ʩչ������������Ҫ��������һ����\n");
   (SCHOLAR_EMBATTLE_DIR+"eight")->start_embattle(me,victim);
   return 1;
}

int help()
{
		write( @C_HELP
ָ���ʽ: embattle <��������> at <����Ŀ��>

���ָ�����������ƶ����ơ�һ����˵һ��������Ϊ�����쵼�˵ĵ�һ����
���������󷨹��У�������ʱ���������Ӷ���ķ��������ƻ�����������
Ҳ���ܱ����˷��������������������Ӷ�ʹ����ʧЧ��
Ψһ�������ǵ���Ҫʩչ������ʱ����Ҫ�������в��裺
1. ��Ҫ����������ɵĶ��飬��Ȼ��������ӡ�
2. һ���������� embattle eight with <another leader name>
3. ��һ����������ʽ�������� embattle eight at <victim name>
4. ����û����,�����������Ὺʼ������
5. ��Ҫʹ��������Ĺ�ϵ��ɢ������ embattle eight disband
������� embattles ָ������㻹�ǵõ����ơ�
C_HELP
		);
    return 1;
}
