// c:/Users/user/Documents/Programming/SFINAE/MetaFunction/IsPointerOf/a.hpp

#pragma once
#include "../a.hpp"

// �W�����ڂ� is_pointer<T> �ƈႢ�A�ǂ̌^�̃|�C���^�[���w�肷��B
// �W�����ڂ� remove_pointer<T> ��p���Ă����l�ɒ�`�ł���B
template <typename T , typename Ret>
class is_PointerOf :
  public EmptySet
{

private:
  template <typename U , typename R>
  static auto Check() -> typename enable_if< is_same<U,R*>::value || is_same<U,const R*>::value , true_type >::type;

  template <typename U , typename R>
  static auto Check() -> typename enable_if< ! ( is_same<U,R*>::value || is_same<U,const R*>::value ) , false_type >::type;

public:
  static const bool value = decltype( Check<T,Ret>() )::value;

};
