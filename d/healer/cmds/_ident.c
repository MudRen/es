//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ident(string arg)
{
  object target;
  string c_realname;
  string realname;
  string s;
  string temp;
  int skills;
  int skill_require;
  int intelligent;
  
  if (! ( arg || arg=="") ) 
    return notify_fail("��Ҫ��ʶʲ�ᶫ��??\n");
  if (! target = present(arg,environment(this_player() ) ) )
    return notify_fail("��Ҫ��ʶ�Ķ����������\n");
  c_realname = target->query("c_realname");
  realname   = target->query("realname");
  skills     = this_player()->query_skill("herbs");
  skill_require = target->query("skill_require");
  intelligent = this_player()->query_stat("int");
  
  tell_room(environment(this_player()),this_player()->query("c_name")+
            "���������ϻ��۾�,����"+target->query("c_name")+
            "��ϸ�Ĺ۲���졣\n",this_player() );
  if ( (! c_realname) || (! realname) || 
     ( skills < skill_require ) || (intelligent <10) )
    return notify_fail("�����"+target->query("c_name")+"��ʶ����,���ǿ�����������Ȼ����\n");
  
  tell_object(this_player(),
              "������ľ���, ���ж�����һ��"+c_realname+"("+realname+")��\n");
  sscanf(identify(target),"%s/%s",s,temp);
  if (this_player()->query_temp("last_verify")==0)
    this_player()->set_temp("last_verify",temp+"\n" );
  else
    this_player()->add_temp("last_verify",temp+"\n" );
  return 1;
}

int help()
{
  write(
  @C_HELP
ָ���ʽ: ident <ֲ����>

���ָ�������ܹ���ȷ��ʶ��һ��ֲ�
���ҩ��ֲ��ܶ඼���ļ�Ϊ����, ������ӱ�ʶ�ͼ��Բɼ�,
�ܿ��ܻᷢ��ҩ�����õ�����, ��������޷��ֲ��Ĵ���, ���
���ϵ��涨����healer�ڲ�ҩǰһ��Ҫ�ȼ��Ա�ʶ��

������޷��ɹ��ı�ʶһ�ֲ�֪����ֲ��, ��������Ϊ����ǻ�
̫��, Ҳ��������Ϊ��ҩ�ݱ�ʶ<herbs> �ļ�����ʶ����, ����
�ȵ������ʵ�Լ�������һ�Ρ�
C_HELP
  );
  return 1;
}
