#define SIZE 20

#include <daemons.h>

mapping levels0;
mapping levels1;
mapping levels2;

string *top_list0;
string *top_list1;
string *top_list2;

string* sort_level(mapping lvs,string* top,string myname);

void log_player (object player)
{
  string *gonfu_name =
    ({ "bolo-fist","power-finger","body-def","keep-flower","dragon-claw",""});
  int my_gonfu, my_exp, my_score, my_align, my_type;
  int *savedata0, *savedata1, *savedata2, *savedata3;
  string myname;
  int i;

  if ( !player || wizardp(player) ) return;
  if ((string)player->query ( "class" ) != "monk" ) return;
  myname = (string)player->query ( "name" );
  if ( wizardp(player) ) return ;

  my_gonfu = 0;
  my_type = 5;
  if ( player->query ( "monk_learn/72" ) ) {
    for (i=0; i<5; i++)
      if ( (string)player->query ( "monk_gonfu/"+gonfu_name[i] ) ) {
        my_gonfu = (int)player->query ( "gonfus_exp/"+gonfu_name[i] );
        my_type = i;
        break;
      }
  }

  my_score = 0;
  if (player->query ( "monk_score" ))
    my_score = (int)player->query ( "monk_score" );
  my_exp   = (int)player->query_experience();

  savedata0 = ({ my_gonfu, my_type });
  savedata1 = ({ my_score, 0 });
  savedata2 = ({ my_exp,   0 });

  if( !levels0 ) levels0 = ([]);
  if( !levels1 ) levels1 = ([]);
  if( !levels2 ) levels2 = ([]);

  if( !top_list0 ) top_list0 = ({});
  if( !top_list1 ) top_list1 = ({});
  if( !top_list2 ) top_list2 = ({});

  levels0[myname] = savedata0;
  levels1[myname] = savedata1;
  levels2[myname] = savedata2;

  top_list0=sort_level (levels0, top_list0, myname);
  top_list1=sort_level (levels1, top_list1, myname);
  top_list2=sort_level (levels2, top_list2, myname);
}

string* sort_level (mapping lvs, string* top, string myname)
{
  int i, loc;

  loc = member_array ( myname, top );
  if ( loc==-1 ) {
    if ( sizeof(top) < SIZE ) {
      loc = sizeof(top);
      top += ({ myname });
    }
    else loc = SIZE;
    while( loc > 0 && (int)lvs[myname][0] >= (int)lvs[top[loc-1]][0] ) {
      if( loc < SIZE ) top[loc] = top[loc-1];
      top[loc-1] = myname;
      loc--;
    }
  }
  else {
    i = loc;
    while ( i > 0 && (int)lvs[myname][0] > (int)lvs[top[i-1]][0] ) {
      if( loc < SIZE ) top[i] = top[i-1];
      top[i-1] = myname;
      i--;
    }
    i = loc;
    while ( i < sizeof(top)-1 && (int)lvs[myname][0] < (int)lvs[top[i+1]][0] ) {
      if ( loc < SIZE ) top[i] = top[i+1];
      top[i+1] = myname;
      i++;
    }
  }
  return top;
}

varargs string get_list ()
{
  string *gonfu_name =
    ({ "������","�������ָ","��ղ�����","�黨ָ","��צ��","" });
  int i, *savedata0, *savedata1, *savedata2, *savedata3;
  string msg;

  if ( !sizeof(top_list0) && !sizeof(top_list1) && !sizeof(top_list2) )
    return  "�Բ�������ɮ�¹�\ѫ��Ŀǰ�ǿյġ�\n";
  msg = "����ɮ�¹�\ѫ��ǰ " + sizeof(top_list2) + " ��:\n";
  msg += "##|  �������   ��ʮ������ ������ | ���  ����   ��\ �� | ���  ����  ������ֵ\n";
  msg += "--+------------ ---------- -------+------------ -------+------------ --------\n";

  for (i=0; i<sizeof(top_list2); i++) {
    savedata0 = levels0[top_list0[i]];
    savedata1 = levels1[top_list1[i]];
    savedata2 = levels2[top_list2[i]];
    msg += sprintf ( "%2d| %-11s %-10s %6d | %-11s %6d | %-11s %8d\n",
      i+1,
      capitalize(top_list0[i]),
        gonfu_name[savedata0[1]],
        savedata0[0],
      capitalize(top_list1[i]),
        savedata1[0],
      capitalize(top_list2[i]),
        savedata2[0]
    );
  }

  return msg;
}

int clean_up()
{
  return 0;
}
