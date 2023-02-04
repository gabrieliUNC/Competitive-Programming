template <typename TYPE>
class Fenny
{
        TYPE *add;
        TYPE *mul;
        size_t length;

        void range_update_helper(size_t pos, TYPE mulfact, TYPE addfact)
        {
            pos += 1;
            while(pos <= length)
            {
                mul[pos - 1] += mulfact;
                add[pos - 1] += addfact;
                pos += pos & -pos;
            }
        }

        Fenny(std::vector<TYPE>& v)
        {
            length = v.size();
            add = new TYPE[length];
            mul = new TYPE[length];

            for(size_t i = 0; i < length; ++i)
            {
                add[i] = 0;
                mul[i] = 0;
            }

            for(size_t i = 0; i < length; ++i)
            {
                point_update(i, v[i]);
            }
        }

        Fenny(TYPE v[], int input_length)
        {
            length = input_length;
            add = new TYPE[length];
            mul = new TYPE[length];

            for(size_t i = 0; i < length; ++i)
            {
                add[i] = 0;
                mul[i] = 0;
            }

            for(size_t i = 0; i < length; ++i)
            {
                point_update(i, v[i]);
            }
        }

        void point_update(size_t i, TYPE val)
        {
            range_update(i, i, val);
        }

        void range_update(size_t i, size_t j, TYPE val)
        {
			range_update_helper(i, val, -val * ((TYPE) i - 1));
			range_update_helper(j, -val, val * j);
            
        }

        TYPE range_sum(size_t i, size_t j)
        {
                if(i > 0)
                {
                    return prefix_sum(j) - prefix_sum(i - 1);
                }
                else
                {
                    return prefix_sum(j);
                }
            }

        TYPE prefix_sum(size_t i)
        {
            TYPE mulfact = 0;
            TYPE addfact = 0;

            size_t startindex = i;
            i += 1;

            while(i > 0)
            {
                addfact += add[i - 1];
                mulfact += mul[i - 1];
                i = i & (i - 1);
            }

            return ((TYPE) startindex) * mulfact + addfact;
        }

        TYPE point_sum(size_t i) {return range_sum(i, i);}

};