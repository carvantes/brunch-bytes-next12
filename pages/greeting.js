// pages/greeting.js

import { useRouter } from 'next/router';
import { useEffect, useState } from 'react';

const Greeting = () => {
  const router = useRouter();
  const [salute, setSalute] = useState('');

  useEffect(() => {
    // Fetch the query parameters from the router object
    const { name } = router.query;

    // Set the salute based on the name query parameter
    if (name) {
      setSalute(`Hello, ${name}!`);
    } else {
      setSalute('Hello!');
    }
  }, [router.query]);

  return (
    <div>
      <h1>{salute}</h1>
      <p>Query parameters: {JSON.stringify(router.query)}</p>
    </div>
  );
};

export default Greeting;