/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:33:49 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 00:24:03 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

template<typename T>
Array<T>::Array() : arr(NULL), sz(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), sz(n) {}

template<typename T>
Array<T>::Array(Array const &copy) : arr(new T[copy.sz]), sz(copy.sz) {
    unsigned int i = 0;
    while(i< sz)
    {
        arr[i] = copy.arr[i];
        i++;
    }
}

template<typename T>
Array<T>::~Array()
{
    delete [] arr;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
    if(this != &copy)
    {
        delete [] arr;
        sz = copy.sz;
        arr = new T[sz];
        
        unsigned int i = 0;
        
        while(i< sz)
        {
            arr[i] = copy.arr[i];
            i++;
        }
    }
    return(*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= sz)
        throw std::out_of_range("Index out of bounds");
    return(arr[i]);
}

template<typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= sz)
        throw std::out_of_range("Index out of bounds");
    return(arr[i]);
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (sz);
}
