#define dead ({"����","����","����","����","���","��̨","�ٻ�" })
#define diff ({ 6,3,5,3,4,3,5 })

int dam,i,acu_sk,con_sk,my_dex,tar_con,tar_dex,tar_dod,diffculty;
string point,part,tar_name,my_name ;
object me,target ;

int sucess(string point,string part) ;
int fail(string point,string part) ;

int remove_block(object obj)
{
    obj->delete_temp("block_command") ;
    return 1 ;
}

int damage(object killer,object tar,string pt,string par)
{
     me = killer ;
     target = tar ;
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_dod = target->query_skill("dodge") ;
       tar_name = target->query("c_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       my_name = me->query("c_name") ;
       tar_name = target->query("c_name") ;
       point = pt ;
       part = par ;
       
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

     if(target == me)
       {
          write("����ɱ��SUICIDE�͹���,��Ҫ̫Ű���Լ���\n") ;
          return -1 ;
       } 
     if(target->query_level()<10)
       {
          write("���������Դ�������ȥ˵��: ��Ҫ�۸�С���ѡ�\n") ;
          tell_room(environment(me),my_name+"����ͻȻ�쵽"+tar_name+
                "��ǰ,����ǧ��һ��֮��,\n������Ī������Ľ��ڰ��, ͷ��ͬʱ���˺ü�������\n",me);
          return -1;
       }  
     me->set_temp("block_command",2) ; 
     target->kill_ob(me) ;
     if(member_array(point,dead)) diffculty = diff[member_array(point,dead)]  ;
    if(random(my_dex*2+acu_sk/2+con_sk/2) > random(tar_dex*diffculty)+tar_dod/2) 
      {
         return sucess(point,part) ;
       }
     else
       {
         return fail(point,part) ;
       }
}

int sucess(string point,string part)
{
    int db = target->query("defense_bonus") ;
    write(sprintf("����������%s%s��%sѨ������ȥ��\n��һ����ҵİ�����,����ʼ�����㡣\n"
                  ,tar_name,part,point) );
    
    me->block_attack(2) ;
    me->set_temp("msg_stop_attack",
            "( һ��Υ����ͳ���¼�ֵ�ı�̬���������������ս���С� ) \n" ) ;
               
    tell_object(target,sprintf(
              "%s����%s��%sѨ������ȥ��\n��һ���ʹ��,�㿪ʼ����%s��\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s�ó�������%s%s������ȥ,����һ���ҽ�,\n%s��ʼ����%s��\n"
              ,my_name,tar_name,part,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ; 

    dam = (((acu_sk+con_sk)*diffculty)/(tar_con+tar_dex))-db/3 ;
    return dam ;   
}

int fail(string point,string part)
{
    write(sprintf("������������%s%s��%sѨ����ȥʱ��\n"
                  "���ƺ������������ͼ����ʼ�����㡣\n"
                  ,tar_name,part,point) );
    
    tell_object(target,sprintf(
              "%s����%s��%sѨ�����������㷢�����������⡣\n"
              "������ȷ����˿�ʼ����%s��\n"
              ,my_name,part,point,my_name) ) ;
                       
    tell_room(environment(me),sprintf(
              "%s�ó�������%s%s������ȥ,����%s���һ��:�� ������ʲ��? ��\n"
              "%s��%s��֪����ľʹ���������\n"
              ,my_name,tar_name,part,tar_name,tar_name,my_name)
              ,({me,target}) ) ;
    call_out("remove_block",3,me) ;
    return -1 ;
}

